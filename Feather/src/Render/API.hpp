#pragma once


#include "Precompiled.hpp"
#include "Math/Vector.hpp"
#include "Render/Vertex.hpp"

namespace Feather::Render {
    class API {
    public:
        static void Draw(const Vertex::Array& vertex);
        static void Draw(const Vertex::Array& vertex, std::size_t count);

        static void Clear(const Math::Float4& color = { 0.0f, 0.0f, 0.0f, 1.0f });

        static void SetViewport(std::size_t x, std::size_t y, std::size_t width, std::size_t height);
    };
}
