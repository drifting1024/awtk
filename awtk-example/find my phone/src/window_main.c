#include "awtk.h"
#include "image_shake.h"

extern ret_t application_init(void);
extern ret_t open_finding_window();
extern ret_t custom_widgets_init();

ret_t custom_widgets_init() {
    //手机晃动自定义
    widget_factory_register(widget_factory(), WIDGET_TYPE_IMAGE_SHAKE, image_shake_create);

    return RET_OK;
}

static ret_t on_start_click(void* ctx, event_t* e) {
  (void)ctx;
  (void)e;

  open_finding_window();

  return RET_OK;
}

/**
 * 子控件初始化(主要是设置click回调、初始显示信息)
 */
static ret_t init_widget(void* ctx, const void* iter) {
  widget_t* widget = WIDGET(iter);
  widget_t* win = widget_get_window(widget);
  (void)ctx;

  if (widget->name != NULL) {
    const char* name = widget->name;

    if (strstr(name, "button_rect") != NULL) {
      widget_on(widget, EVT_CLICK, on_start_click, win);
    }
  }

  return RET_OK;
}

/**
 * 初始化窗口上的子控件
 */
static void init_children_widget(widget_t* widget) {
  widget_foreach(widget, init_widget, widget);
}

/**
 * 初始化
 */
ret_t application_init() {
  widget_t* system_bar = window_open("system_bar/system_bar");
  widget_t* system_bar_b = window_open("system_bar_b/system_bar_b");
  widget_t* win;
  widget_t* winman;
  ret_t ret;

  custom_widgets_init();
  win = window_open("home_page/home_page");
  
  if (win) {
    init_children_widget(win);
  }

  winman = window_manager();
  ret = window_manager_set_show_fps(winman, 1);

  return RET_OK;
}
