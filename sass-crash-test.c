#include <sass.h>
#include <sass_context.h>

int
main()
{
  struct Sass_Data_Context *dc;
  struct Sass_Context *c;
  struct Sass_Options *o;
  dc = sass_make_data_context("/* First */");
  c = sass_data_context_get_context(dc);
  sass_option_set_output_path(o, "file.css");
  return sass_compile_data_context(dc);
}

