#include "awtk.h"
#include "custom_widgets/custom_widgets.h"

extern ret_t application_init(void);
extern ret_t open_line_series_window(const char* name);
/**
 * 子控件初始化(主要是设置click回调、初始显示信息)
 */
static ret_t init_widget(void* ctx, const void* iter) {
  widget_t* widget = WIDGET(iter);
  widget_t* win = widget_get_window(widget);
  (void)ctx;

  if (widget->name != NULL) {
    const char* name = widget->name;

    if (strstr(name, "chart_view") != NULL) {
//      widget_on(widget, EVT_CLICK, on_start_click, win);
      win = win;
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

extern void test_series(widget_t* widget);
/**
 * 初始化
 */
ret_t application_init() {
  /* 初始化自定义控件 */
  custom_widgets_init();  
  
  widget_t* system_bar = window_open("system_bar/system_bar");
  widget_t* system_bar_b = window_open("system_bar_b/system_bar_b");
  widget_t* win = window_open("home_page/home_page");



  if (win) {
    init_children_widget(win);
    // open_line_series_window("window_line_series/window_line_series");
    // init_normal_line_series_window(win);
    // axis_time_init(win);    
    test_series(win);
  }

  return RET_OK;
}
