#include <sass.h>
#include <sass/context.h>

int
main()
{
  struct Sass_File_Context *dc;
  dc = sass_make_file_context("file.scss");
  return sass_compile_file_context(dc);
}

