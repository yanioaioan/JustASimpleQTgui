#ifndef NGLSCENE_H
#define NGLSCENE_H

#include <QGLWidget>

class NGLScene: public QGLWidget
{
    Q_OBJECT
public:
    NGLScene(QWidget *_parent);
    ~NGLScene();

    float m_rColor;

protected:
    void initializeGL ();
    void resizeGL (int _w, int _h);
    void paintGL ();
private:
    void mouseMoveEvent (QMouseEvent * _event);
    void mousePressEvent (QMouseEvent * _event);

signals:
    void clicked(bool);

public slots:
  void testButtonClicked(bool);

};

#endif // NGLSCENE_H
