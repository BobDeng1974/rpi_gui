/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_ui_WRAP_H_
#define SWIG_ui_WRAP_H_

#include <map>
#include <string>


class SwigDirector_Widget : public Widget, public Swig::Director {

public:
    SwigDirector_Widget(PyObject *self, int x, int y, int width, int height, char const *name = "", Widget *parent = NULL);
    virtual void parent_resize_event(IBbox const &bbox);
    virtual void parent_resize_eventSwigPublic(IBbox const &bbox) {
      Widget::parent_resize_event(bbox);
    }
    virtual bool enter_event();
    virtual bool enter_eventSwigPublic() {
      return Widget::enter_event();
    }
    virtual bool leave_event();
    virtual bool leave_eventSwigPublic() {
      return Widget::leave_event();
    }
    virtual bool key_press_event(char const *code);
    virtual bool key_press_eventSwigPublic(char const *code) {
      return Widget::key_press_event(code);
    }
    virtual bool key_release_event(char const *code);
    virtual bool key_release_eventSwigPublic(char const *code) {
      return Widget::key_release_event(code);
    }
    virtual bool mouse_press_event(int button);
    virtual bool mouse_press_eventSwigPublic(int button) {
      return Widget::mouse_press_event(button);
    }
    virtual bool mouse_release_event(int button);
    virtual bool mouse_release_eventSwigPublic(int button) {
      return Widget::mouse_release_event(button);
    }
    virtual bool mouse_wheel_event(int button);
    virtual bool mouse_wheel_eventSwigPublic(int button) {
      return Widget::mouse_wheel_event(button);
    }
    virtual bool mouse_motion_event(int x, int y);
    virtual bool mouse_motion_eventSwigPublic(int x, int y) {
      return Widget::mouse_motion_event(x,y);
    }
    virtual bool drag_event(int rel_x, int rel_y);
    virtual bool drag_eventSwigPublic(int rel_x, int rel_y) {
      return Widget::drag_event(rel_x,rel_y);
    }
    virtual void timer_event(void *data);
    virtual void timer_eventSwigPublic(void *data) {
      Widget::timer_event(data);
    }
    virtual bool custom_event(void *data);
    virtual bool custom_eventSwigPublic(void *data) {
      return Widget::custom_event(data);
    }
    virtual bool accept_drag(int x, int y);
    virtual bool accept_dragSwigPublic(int x, int y) {
      return Widget::accept_drag(x,y);
    }
    virtual void widget_added_event(Widget *widget);
    virtual void widget_added_eventSwigPublic(Widget *widget) {
      Widget::widget_added_event(widget);
    }
    virtual void init_viewport(int x, int y, int width, int height);
    virtual void init_viewportSwigPublic(int x, int y, int width, int height) {
      Widget::init_viewport(x,y,width,height);
    }
    virtual void draw();
    virtual void drawSwigPublic() {
      Widget::draw();
    }
    virtual void post_draw();
    virtual void post_drawSwigPublic() {
      Widget::post_draw();
    }
    virtual ~SwigDirector_Widget();
    virtual void resize(int x, int y, int w, int h);
    virtual void resize(int w, int h);


/* Internal Director utilities */
public:
    bool swig_get_inner(const char* name) const {
      std::map<std::string, bool>::const_iterator iv = inner.find(name);
      return (iv != inner.end() ? iv->second : false);
    }

    void swig_set_inner(const char* name, bool val) const
    { inner[name] = val;}

private:
    mutable std::map<std::string, bool> inner;


#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (method == NULL) {
          std::string msg = "Method in class Widget doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      };
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[19];
#endif

};


class SwigDirector_Button : public Button, public Swig::Director {

public:
    SwigDirector_Button(PyObject *self, int x, int y, int width, int height, char const *name = "", Widget *parent = NULL);
    virtual void parent_resize_event(IBbox const &bbox);
    virtual void parent_resize_eventSwigPublic(IBbox const &bbox) {
      Widget::parent_resize_event(bbox);
    }
    virtual bool enter_event();
    virtual bool leave_event();
    virtual bool key_press_event(char const *code);
    virtual bool key_press_eventSwigPublic(char const *code) {
      return Widget::key_press_event(code);
    }
    virtual bool key_release_event(char const *code);
    virtual bool key_release_eventSwigPublic(char const *code) {
      return Widget::key_release_event(code);
    }
    virtual bool mouse_press_event(int button);
    virtual bool mouse_release_event(int button);
    virtual bool mouse_wheel_event(int button);
    virtual bool mouse_wheel_eventSwigPublic(int button) {
      return Widget::mouse_wheel_event(button);
    }
    virtual bool mouse_motion_event(int x, int y);
    virtual bool mouse_motion_eventSwigPublic(int x, int y) {
      return Widget::mouse_motion_event(x,y);
    }
    virtual bool drag_event(int rel_x, int rel_y);
    virtual bool drag_eventSwigPublic(int rel_x, int rel_y) {
      return Widget::drag_event(rel_x,rel_y);
    }
    virtual void timer_event(void *data);
    virtual void timer_eventSwigPublic(void *data) {
      Widget::timer_event(data);
    }
    virtual bool custom_event(void *data);
    virtual bool custom_eventSwigPublic(void *data) {
      return Widget::custom_event(data);
    }
    virtual bool accept_drag(int x, int y);
    virtual bool accept_dragSwigPublic(int x, int y) {
      return Widget::accept_drag(x,y);
    }
    virtual void widget_added_event(Widget *widget);
    virtual void widget_added_eventSwigPublic(Widget *widget) {
      Widget::widget_added_event(widget);
    }
    virtual void init_viewport(int x, int y, int width, int height);
    virtual void init_viewportSwigPublic(int x, int y, int width, int height) {
      Widget::init_viewport(x,y,width,height);
    }
    virtual void draw();
    virtual void drawSwigPublic() {
      Button::draw();
    }
    virtual void post_draw();
    virtual void post_drawSwigPublic() {
      Widget::post_draw();
    }
    virtual ~SwigDirector_Button();
    virtual void resize(int x, int y, int w, int h);
    virtual void resize(int w, int h);


/* Internal Director utilities */
public:
    bool swig_get_inner(const char* name) const {
      std::map<std::string, bool>::const_iterator iv = inner.find(name);
      return (iv != inner.end() ? iv->second : false);
    }

    void swig_set_inner(const char* name, bool val) const
    { inner[name] = val;}

private:
    mutable std::map<std::string, bool> inner;


#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (method == NULL) {
          std::string msg = "Method in class Button doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      };
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[19];
#endif

};


class SwigDirector_Layout : public Layout, public Swig::Director {

public:
    SwigDirector_Layout(PyObject *self, int x, int y, int w, int h, char const *name = "", Widget *parent = NULL, Layout_style style = LAYOUT_VERTICAL);
    virtual void parent_resize_event(IBbox const &bbox);
    virtual bool enter_event();
    virtual bool enter_eventSwigPublic() {
      return Widget::enter_event();
    }
    virtual bool leave_event();
    virtual bool leave_eventSwigPublic() {
      return Widget::leave_event();
    }
    virtual bool key_press_event(char const *code);
    virtual bool key_press_eventSwigPublic(char const *code) {
      return Widget::key_press_event(code);
    }
    virtual bool key_release_event(char const *code);
    virtual bool key_release_eventSwigPublic(char const *code) {
      return Widget::key_release_event(code);
    }
    virtual bool mouse_press_event(int button);
    virtual bool mouse_press_eventSwigPublic(int button) {
      return Widget::mouse_press_event(button);
    }
    virtual bool mouse_release_event(int button);
    virtual bool mouse_release_eventSwigPublic(int button) {
      return Widget::mouse_release_event(button);
    }
    virtual bool mouse_wheel_event(int button);
    virtual bool mouse_wheel_eventSwigPublic(int button) {
      return Widget::mouse_wheel_event(button);
    }
    virtual bool mouse_motion_event(int x, int y);
    virtual bool mouse_motion_eventSwigPublic(int x, int y) {
      return Widget::mouse_motion_event(x,y);
    }
    virtual bool drag_event(int rel_x, int rel_y);
    virtual bool drag_eventSwigPublic(int rel_x, int rel_y) {
      return Widget::drag_event(rel_x,rel_y);
    }
    virtual void timer_event(void *data);
    virtual void timer_eventSwigPublic(void *data) {
      Widget::timer_event(data);
    }
    virtual bool custom_event(void *data);
    virtual bool custom_eventSwigPublic(void *data) {
      return Widget::custom_event(data);
    }
    virtual bool accept_drag(int x, int y);
    virtual bool accept_dragSwigPublic(int x, int y) {
      return Widget::accept_drag(x,y);
    }
    virtual void widget_added_event(Widget *widget);
    virtual void widget_added_eventSwigPublic(Widget *widget) {
      Layout::widget_added_event(widget);
    }
    virtual void init_viewport(int x, int y, int width, int height);
    virtual void init_viewportSwigPublic(int x, int y, int width, int height) {
      Widget::init_viewport(x,y,width,height);
    }
    virtual void draw();
    virtual void drawSwigPublic() {
      Widget::draw();
    }
    virtual void post_draw();
    virtual void post_drawSwigPublic() {
      Widget::post_draw();
    }
    virtual ~SwigDirector_Layout();
    virtual void resize(int x, int y, int w, int h);
    virtual void resize(int w, int h);


/* Internal Director utilities */
public:
    bool swig_get_inner(const char* name) const {
      std::map<std::string, bool>::const_iterator iv = inner.find(name);
      return (iv != inner.end() ? iv->second : false);
    }

    void swig_set_inner(const char* name, bool val) const
    { inner[name] = val;}

private:
    mutable std::map<std::string, bool> inner;


#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (method == NULL) {
          std::string msg = "Method in class Layout doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      };
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[19];
#endif

};


#endif
