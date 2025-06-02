#pragma once
#include <unordered_map>
#include <typeindex>
#include <memory>
#include <vector>
#include <cassert>
#include "Entity.h"

class IComponentArray {
public:
    virtual ~IComponentArray() = default;
    virtual void removeEntity(Entity entity) = 0;
    virtual bool hasEntity(Entity entity) const = 0;
};

template<typename T>
class ComponentArray : public IComponentArray {
    std::unordered_map<Entity, T> components;
public:
    void insert(Entity entity, const T& component) { components[entity] = component; }
    void remove(Entity entity) override { components.erase(entity); }
    T* get(Entity entity) {
        auto it = components.find(entity);
        if (it != components.end()) return &it->second;
        return nullptr;
    }
    bool has(Entity entity) const override { return components.count(entity) > 0; }
    void removeEntity(Entity entity) override { remove(entity); }

    // ��� ������� ���� Entity � ���� �����������
    std::vector<Entity> entities() const {
        std::vector<Entity> result;
        for (const auto& [entity, comp] : components)
            result.push_back(entity);
        return result;
    }
};

class ComponentManager {
    std::unordered_map<std::type_index, std::unique_ptr<IComponentArray>> componentArrays;
public:
    template<typename T>
    ComponentArray<T>& getArray() {
        auto type = std::type_index(typeid(T));
        if (!componentArrays.count(type)) {
            componentArrays[type] = std::make_unique<ComponentArray<T>>();
        }
        return *static_cast<ComponentArray<T>*>(componentArrays[type].get());
    }

    template<typename T>
    void addComponent(Entity entity, const T& component) {
        getArray<T>().insert(entity, component);
    }

    template<typename T>
    void removeComponent(Entity entity) {
        getArray<T>().remove(entity);
    }

    template<typename T>
    T* getComponent(Entity entity) {
        return getArray<T>().get(entity);
    }

    template<typename T>
    bool hasComponent(Entity entity) const {
        auto type = std::type_index(typeid(T));
        auto it = componentArrays.find(type);
        if (it == componentArrays.end()) return false;
        return static_cast<ComponentArray<T>*>(it->second.get())->has(entity);
    }

    // ������� ��� ����������, ��������� � ������ ���������
    void removeEntity(Entity entity) {
        for (auto& [type, array] : componentArrays) {
            array->removeEntity(entity);
        }
    }

    // Entity Query: �������� ��� ��������, � ������� ���� ��� ��������� ����������
    template<typename... Components>
    std::vector<Entity> entitiesWith() {
        constexpr size_t N = sizeof...(Components);
        static_assert(N > 0, "������ ���� ���� �� ���� ���������");

        // �������� ������� �����������
        std::vector<const IComponentArray*> arrays = { &getArray<Components>()... };

        // ���� �� ������ ������ ������ (�������, ��� ������ ����������� ���� Position ������ �����)
        const auto* baseArray = static_cast<const ComponentArray<std::tuple_element_t<0, std::tuple<Components...>>>*>(arrays[0]);
        std::vector<Entity> candidates = baseArray->entities();

        std::vector<Entity> result;
        for (Entity e : candidates) {
            bool hasAll = true;
            // ��������� ������� ��������� �����������
            size_t idx = 1;
            ((hasAll &= static_cast<const ComponentArray<Components>*>(arrays[idx++])->has(e)), ...);
            if (hasAll) result.push_back(e);
        }
        return result;
    }
};