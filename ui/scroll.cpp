/***
 *     ____    ____   _____ ____   ____     ___  ____   ____   __ __       ____  __ __  ____
 *    |    \  /    | / ___/|    \ |    \   /  _]|    \ |    \ |  |  |     /    ||  |  ||    |
 *    |  D  )|  o  |(   \_ |  o  )|  o  ) /  [_ |  D  )|  D  )|  |  |    |   __||  |  | |  |
 *    |    / |     | \__  ||   _/ |     ||    _]|    / |    / |  ~  |    |  |  ||  |  | |  |
 *    |    \ |  _  | /  \ ||  |   |  O  ||   [_ |    \ |    \ |___, |    |  |_ ||  :  | |  |
 *    |  .  \|  |  | \    ||  |   |     ||     ||  .  \|  .  \|     |    |     ||     | |  |
 *    |__|\_||__|__|  \___||__|   |_____||_____||__|\_||__|\_||____/     |___,_| \__,_||____|
 *
 * (C) 2017 Cedric PAILLE (cedricpaille(at)gmail.com)
 */

#include "scroll.h"

Scroll::Scroll(int x, int y, int width, int height, const char* name, Widget* parent) : Widget(x, y, width, height, name, parent)
{
	m_scroll_widget = NULL;
	m_oldx = m_oldy = 0;
	// We don't want to resize content
	resize_children(false);
	if (m_children_widgets.size() > 0){
		set_scroll_widget(m_children_widgets[0]);
	}
}

bool
Scroll::drag_event(int rel_x, int rel_y)
{
	if (!m_scroll_widget)
		return false;

	int new_pos_x = m_oldx - rel_x;
	int new_pos_y = m_oldy - rel_y;
	int scroll_widget_w = m_scroll_widget->w();
	int scroll_widget_h = m_scroll_widget->h();

	if (new_pos_x < -(scroll_widget_w - w()))
		new_pos_x = -(scroll_widget_w - w());

	if (new_pos_y < -(scroll_widget_h - h()))
		new_pos_y = -(scroll_widget_h - h());

	new_pos_x = new_pos_x > 0 ? 0 : new_pos_x;
	new_pos_y = new_pos_y > 0 ? 0 : new_pos_y;

	m_scroll_widget->x(new_pos_x);
	m_scroll_widget->y(new_pos_y);

	dirty(true);
	return true;
}

void
Scroll::set_scroll_widget(Widget* scroll_widget)
{
	if (m_children_widgets.size() > 1){
		std::cerr << "Scroll::set_scroll_widget : cannot manage more than one children widget" << std::endl;
	}
	if (!scroll_widget){
		std::cerr << "Scroll::set_scroll_widget : inserting NULL widget" << std::endl;
		return;
	}
	m_scroll_widget = scroll_widget;
	if (m_scroll_widget->parent() != this){
		m_scroll_widget->parent(this);
	}
	reset();
}

void
Scroll::reset()
{
	if (!m_scroll_widget)
		return;
	m_scroll_widget->x(0);
	m_scroll_widget->y(0);
	dirty(true);
}

bool
Scroll::accept_drag(int x, int y)
{
	if (!m_scroll_widget)
		return false;
	m_oldx = m_scroll_widget->x();
	m_oldy = m_scroll_widget->y();
	return true;
}

void Scroll::widget_added_event(Widget* widget)
{
	set_scroll_widget(widget);
}

void
Scroll::draw()
{

}
