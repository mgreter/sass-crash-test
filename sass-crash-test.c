#include <sass.h>
#include <sass_context.h>

int
main()
{
  struct Sass_File_Context *dc;
  struct Sass_Context *c;
  struct Sass_Options *o;
  dc = sass_make_file_context("file.scss");
  c = sass_file_context_get_context(dc);
  sass_option_set_output_path(o, "file.css");
  return sass_compile_file_context(dc);
}

