#include "stdafx.h"
#include "Application.h"


Application::Application()
{
    isRun = true;
}


Application::~Application()
{
}

void Application::toggle()
{
    bool _run = isRun;
    isRun = !_run;
  
}

bool Application::run()
{
    return isRun;
}
