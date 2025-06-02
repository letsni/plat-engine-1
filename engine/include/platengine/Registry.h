#pragma once
#include "Entity.h"
#include "ComponentManager.h"
#include <unordered_map>
#include <typeindex>
#include <memory>
#include <set>

class Registry {
    Entity nextEntity = 1;
    std::set<Entity> aliveEntities;
    std::unordered_map<std::type_index, std::unique_ptr<IComponentArray>> componentArrays;

    template<typename T>
    ComponentArray<T>& getArray() {
        std::type_index ti(typeid(T));
        if (!componentArrays.count(ti))
            componentArrays[ti] = std::make_unique<ComponentArray<T>>();
        return *static_cast<ComponentArray<T>*>(componentArrays[ti].get());
    }
public:
    Entity createEntity() { aliveEntities.insert(nextEntity); return nextEntity++; }
    void destroyEntity(Entity entity) { aliveEntities.erase(entity); /* remove from arrays */ }

    template<typename T>
    void addComponent(Entity entity, const T& component) { getArray<T>().insert(entity, component); }
    template<typename T>
    void removeComponent(Entity entity) { getArray<T>().remove(entity); }
    template<typename T>
    T* getComponent(Entity entity) { return getArray<T>().get(entity); }
    template<typename T>
    bool hasComponent(Entity entity) const { return getArray<T>().has(entity); }
    const std::set<Entity>& getAliveEntities() const { return aliveEntities; }
};