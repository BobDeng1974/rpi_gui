#include "button.h"
#include "string_utils.h"

Button::Button(int x, int y, int width, int height, const char* name, Widget* parent) : Widget(x, y, width, height, name, parent)
{
	m_color_push = FColor(1., 1., 1., 1);
	m_color_hover = FColor(1., 1., 1., .9);
	m_original_fg = FColor(1., 1., 1., .8);
	m_fgcolor = m_original_fg;
	m_image_id = -1;
	m_imgh = m_imgw = 0;
	m_label = name;
}

void
Button::set_image(std::string image_filename)
{
	std::string image_name = string_basename(image_filename);
	m_image_id = painter().create_texture_svg(image_name, image_filename);
	if (m_image_id == -1){
		std::cerr << "Button::set_image : Image not loaded " <<  image_filename << std::endl;
		m_imgh = m_imgw = 0;
		return;
	}
	painter().texture_size(image_name, m_imgw, m_imgh);
}

void
Button::draw(){
	int x = (w() - m_imgw) / 2;
	int y = (h() - m_imgh) / 2;

	painter().use_texture(m_image_id);
	painter().enable_alpha(true);
	painter().draw_quad(x, y, m_imgw, m_imgh, true);

	if (!m_label.empty()){
		IBbox bound(painter().bound_text(m_font_id, m_label.c_str()));
		int xt = (w() - bound.width()) / 2;
		int yt = (h() - bound.height()) / 2 + bound.height() / 2;
		painter().draw_text(m_font_id, m_label.c_str(), xt, yt);
	}
}

bool
Button::mouse_press_event(int button){
	if (button != EVENT_MOUSE_BUTTON_LEFT)
		return false;
	m_fgcolor = m_color_push;
	dirty(true);
	return true;
}

bool
Button::mouse_release_event(int button){
	m_fgcolor = m_color_hover;
	do_callback();
	dirty(true);
	return true;
}

bool
Button::enter_event(){
	m_fgcolor = m_color_hover;
	dirty(true);
	return true;
}

bool
Button::leave_event(){
	m_fgcolor = m_original_fg;
	dirty(true);
	return true;
}
