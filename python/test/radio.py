# -*- coding: utf-8 -*-
import sys, os
sys.path.append("/sources/GUI/BUILD_X86/python")
import ui


class Navit_control(ui.Widget):
    def __init__(self, X=0, Y=0, W=0, H=0, name='', parent = None):
        super(Navit_control, self).__init__(X, Y, W, H, name, parent)
        self.navit_widget = ui.Navit_widget()
        self.layout_h = ui.Layout()
        self.layout_h.style(ui.LAYOUT_HORIZONTAL)
        
        self.layout_v = ui.Layout()
        self.layout_v.style(ui.LAYOUT_VERTICAL)
        
        self.zoom_in = ui.Button()
        self.zoom_in.label("ZOOM IN")
        self.zoom_in.style(ui.Button.STYLE_CARBON)
        
        self.zoom_out = ui.Button()
        self.zoom_out.label("ZOOM OUT")
        self.zoom_out.style(ui.Button.STYLE_CARBON)
        
        self.zoom_in.callback(self.zoom_cb, 0)
        self.zoom_out.callback(self.zoom_cb, 1)
        
        self.layout_v.fixed_width(80)
        
        self.zoom_in.parent(self.layout_v)
        self.zoom_out.parent(self.layout_v)
        
        self.layout_v.parent(self.layout_h)
        self.navit_widget.parent(self.layout_h)
        self.layout_h.parent(self)     
           
    def zoom_cb(self, data):
        if data == 0:
            self.navit_widget.zoom(True)
        else:
            self.navit_widget.zoom(False)


class Test(ui.Widget):
     def __init__(self, X=0, Y=0, W=0, H=0, name='Eager', parent = None):
        super(Test, self).__init__(X, Y, W, H, name, parent)
        vtx = [10., 0., 6., 70., 4., 70., 0., 0.]
        data = ui.vertex_container(vtx)
        self.v = self.painter().create_polygon_2d(data)
        self.add_timer(5)
        self.r = 10.
        self.backbuffer_refresh(False)
        
        #self.wid = ui.Button(0,0,200,200, "OK?")
        #self.wid.callback(self.cb, self.wid)
        #self.wid.hide()
        
#     def mouse_release_event(self, but):
#        self.wid.resize(200,200)
#        self.wid.modal(300,140)
     
#     def cb(self, data):
#        print "CB"
#        self.wid.hide()
     
     def timer_event(self, data):
        if self.hidden():
            return False
        self.r += 1.
        self.dirty(True)
        return True
        
     def draw(self):
        area = self.drawing_area()
        self.push_model_matrix()
        self.translate(area.width()/2., area.height()/2., 0.)
        self.rotate(0,0,1,self.r)
        self.translate(-10, -20, 0.)
        self.scale(2,2,2)
        self.painter().disable_texture()
        self.painter().draw_solid_polygon_2d(self.v)
        self.pop_model_matrix()


class Radio(ui.Widget):
    def __init__(self, X, Y, W, H, name, parent):
        super(Radio, self).__init__(X, Y, W, H, name, parent)
        # Enable background tiling
        self.tiles_enabled(True)
        
        # Define layouts
        self.layout_v = ui.Layout(0, 0,self.w(), self.h(),"global_layout", self, ui.LAYOUT_VERTICAL)
        self.layout_tune = ui.Layout(0, 0, self.w(), 85,"radio_layout", self.layout_v, ui.LAYOUT_HORIZONTAL)
        self.layout_tune.fixed_height(85)
        
        self.tune_display = ui.Label()
        self.bigfonts = self.tune_display.load_fonts("fonts/custom.ttf", 80)
        self.tune_display.fixed_width(300)
        self.tune_display.fg_color(ui.FColor(.2,.2,.8,1.))
        self.tune_display.label("107.70")
        
        self.button_scan_low = ui.Button(0, 0, 80, 0)
        self.button_scan_low.use_fonts_id(self.bigfonts)
        self.button_scan_low.label("<<")
        
        self.button_scan_hi = ui.Button(0, 0, 80, 0)
        self.button_scan_hi.use_fonts_id(self.bigfonts)
        self.button_scan_hi.label(">>")
        
        self.rds_display = ui.Label()
        self.rds_display.fg_color(ui.FColor(.4,.2,.4,1.))
        self.rds_display.use_fonts_id(self.bigfonts)
        self.rds_display.fixed_height(80)
        self.rds_display.backgroung_gradient_enable(True)
        self.rds_display.gradient(ui.FColor(.0,.0,.0,1), ui.FColor(.7,.7,.7,1))
        self.rds_display.tiles_enabled(True)
        self.rds_display.label("RADIO #1")
        
        self.lay = ui.Layout(0, 0, self.w(), 85,"??", None, ui.LAYOUT_HORIZONTAL)
        self.file_man = ui.File_chooser()
        self.file_man2 = Test()
      
        self.layout_tune.add_widget(self.button_scan_low)
        self.layout_tune.add_widget(self.tune_display)
        self.layout_tune.add_widget(self.button_scan_hi)
        
        self.layout_v.add_widget(self.rds_display)
        self.lay.add_widget(self.file_man)
        self.lay.add_widget(self.file_man2)
        self.layout_v.add_widget(self.lay)

    def key_press_event(self, keycode):
        print keycode

comp = ui.get_compositor()
comp.init(800, 480)

window = comp.create_new_window()
panel = ui.Multi_panel(0,0,window.w(), window.h(), "MP", window)
panel.buttons_ratio(8)

radio_tab = Radio(0,0, 200, 200, "RADIO", window)
x = ui.Button(0,0, 200, 200, "MUSIC", panel)
navit = Navit_control(0,0,0,0,"NAVIT")

but1=panel.add_tab(radio_tab)
but2=panel.add_tab(x)
but3=panel.add_tab(navit)


comp.run()

