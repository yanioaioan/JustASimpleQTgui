#include "nglscene.h"
#include <iostream>

NGLScene::NGLScene(QWidget *_parent): QGLWidget(_parent)
{
    setFocus ();
    this->resize(_parent->size ());
}

NGLScene::~NGLScene()
{
}

void NGLScene::initializeGL ()
{
    glClearColor (0.4,0.4,0.4,1);
    glEnable (GL_DEPTH);
}
void NGLScene::resizeGL (int _w,int _h)
{
    glViewport (0,0,_w,_h);
}
void NGLScene::paintGL ()
{
    glClearColor (m_rColor,0.4,0.4,1);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}



void NGLScene::mouseMoveEvent (QMouseEvent * _event){}
void NGLScene::mousePressEvent (QMouseEvent *_event){}

void NGLScene::testButtonClicked(bool b)
{
    emit clicked (b);
    std::cout<<"Button Clicked - manual signal-slot connection"<<std::endl;
    m_rColor=1;
    updateGL ();
}
