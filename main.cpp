#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <assert.h>

#define GL_CHECK(call) \
        do {           \
            call;      \
            GLenum glerr = glGetError(); \
            assert(glerr == GL_NO_ERROR);\
        } while(0)
    

int main(int argc, char* argv[])
{
    (void)argc; (void)argv;
    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(
        SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG
        );
    SDL_GL_SetAttribute(
        SDL_GL_CONTEXT_MAJOR_VERSION, 3
        );
    SDL_GL_SetAttribute(
        SDL_GL_CONTEXT_MINOR_VERSION, 3
        );
    SDL_GL_SetAttribute(
        SDL_GL_DOUBLEBUFFER, 1
        );
    SDL_GL_SetAttribute(
        SDL_GL_RED_SIZE, 8
        );
    SDL_GL_SetAttribute(
        SDL_GL_GREEN_SIZE, 8
        );
    SDL_GL_SetAttribute(
        SDL_GL_BLUE_SIZE, 8
        );
    SDL_GL_SetAttribute(
        SDL_GL_ALPHA_SIZE, 8
        );

    SDL_Window* window = SDL_CreateWindow(
        "Ikkuna",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640,
        480,
        SDL_WINDOW_OPENGL
        );

    SDL_GLContext context = SDL_GL_CreateContext(window);

    glewExperimental = GL_TRUE;
    glewInit();

    glClearColor(0.5f, 0.5f, 0.5f, 1.f);

    bool running = true;

    while (running)
    {
        SDL_Event ev;
        while (SDL_PollEvent(&ev))
        {
            if (ev.type == SDL_QUIT)
                running = false;
        }
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}