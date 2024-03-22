#include "DefaultGraphicsContentProvider.h"


DefaultGraphicsContentProvider::DefaultGraphicsContentProvider() {
        shapeMap = std::map<int, BaseDrawableShape*>();
        registrationCounter = 0;
}


DefaultGraphicsContentProvider::~DefaultGraphicsContentProvider() {
        for (const auto& [key, value] : shapeMap) {
                delete value;
        }

        shapeMap.clear();
}


int DefaultGraphicsContentProvider::RegisterContent(BaseDrawableShape* shapeToRegister) {
        int currentId = registrationCounter.fetch_add(1);
        shapeMap.insert({ currentId, shapeToRegister });
        return currentId;
}


bool DefaultGraphicsContentProvider::HasContentWithId(int idToCheck) {
        return shapeMap.count(idToCheck) > 0;
}


bool DefaultGraphicsContentProvider::TryUnregisterContent(int id, bool throwIfNotFound) {
        if (throwIfNotFound && !HasContentWithId(id))
                throw new std::invalid_argument("Ключ не найден в реестре отрисовываемых объектов");

        bool wasInMap = HasContentWithId(id);
        shapeMap.erase(id);
        return wasInMap;
}


void DefaultGraphicsContentProvider::DrawContent(GLFWwindow* window) {
        for (const auto &[key, value] : shapeMap) {
                value->Draw(window);
        }
}


void DefaultGraphicsContentProvider::OnKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mode) {

}
