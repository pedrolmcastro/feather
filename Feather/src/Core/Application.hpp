#pragma once


#include "Core/Layer.hpp"
#include "Core/Memory.hpp"
#include "Input/Event.hpp"
#include "Render/Window.hpp"
#include "Render/Context.hpp"

namespace Feather {
    class Application {
    public:
        Application(std::string name, unsigned width, unsigned height, bool vsync = true);
        virtual ~Application();

        // Defined by the client
        static Unique<Application> Create();

        void Run();
    protected:
        void Push(Unique<Layer::Layer> layer) { layers.Push(std::move(layer)); }
        Unique<Layer::Layer> Pop() { return layers.Pop(); }
    private:
        Render::Context context;
        Layer::Stack layers;
        bool running = true;
        Window window;

        void OnEvent(Event::Event& event);
        bool OnWindowClose(Event::WindowClose& event);
    };
}
