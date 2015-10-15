#include "nglscene.h"
#include <iostream>

NGLScene::NGLScene(/*QWidget *_parent*/)//: QGLWidget(_parent)
{
    setFocus ();
    m_rColor=1;
    m_gColor=1;
    m_bColor=1;
//    this->resize(_parent->size ());
}

NGLScene::~NGLScene()
{
}

void NGLScene::initializeGL ()
{
    glClearColor (0.4,0.4,0.4,1);
    glEnable (GL_DEPTH);
}

void NGLScene::resizeGL(int w, int h)
{
  // set the viewport for openGL we need to take into account retina display
  // etc by using the pixel ratio as a multiplyer
  glViewport(0,0,w*devicePixelRatio(),h*devicePixelRatio());
  // now set the camera size values as the screen size has changed
  update();
}

void NGLScene::paintGL ()
{
    std::cout<<m_rColor<<", "<<m_gColor<<", "<<m_bColor<<std::endl;
    glClearColor (m_rColor,m_gColor,m_bColor,1);

//    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}



void NGLScene::mouseMoveEvent (QMouseEvent * _event){}
void NGLScene::mousePressEvent (QMouseEvent *_event){}

void NGLScene::testButtonClicked(bool b)
{
    emit clicked (b);
    std::cout<<"Button Clicked - manual signal-slot connection"<<std::endl;
    m_rColor=ngl::Random::instance()->randomNumber(1);
    m_gColor=ngl::Random::instance()->randomNumber(1);
    m_bColor=ngl::Random::instance()->randomNumber(1);

    update();
}
