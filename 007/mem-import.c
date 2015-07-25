#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <sass.h>
#include <sass_context.h>

static Sass_Import_List local_import(const char *cur_path, Sass_Importer_Entry info, struct Sass_Compiler *comp);

/* ARGSUSED */
static Sass_Import_List
local_import(const char *cur_path,
             Sass_Importer_Entry info,
             struct Sass_Compiler *comp)
{
  Sass_Import_List sl;
  fprintf(stderr, "Importing:%s\n", cur_path); 
  sl = sass_make_import_list(1);
  sl[0] = sass_make_import_entry("static", strdup("/* import */"), strdup(""));
  return sl;
}

int
main()
{
  char data[120];
  struct Sass_Data_Context *dc;
  struct Sass_Context *c;
  struct Sass_Options *o;
  char *data0;
  const char *out;
  int rc;

  Sass_Importer_List c_importers;

  strncpy(data,
      "@import \"lala\";\n"
      "@import \"delta\";\n"
      "/* First */ a { color: red; }",
    sizeof(data));
  data0 = strdup(data);
  dc = sass_make_data_context(data0);
  c = sass_data_context_get_context(dc);
  o = sass_context_get_options(c);
  sass_option_set_output_path(o, "file.css");

  c_importers = sass_make_importer_list(1);
  c_importers[0] = sass_make_importer(local_import, 0, NULL);
  sass_option_set_c_importers(o, c_importers);

  if ((rc = sass_compile_data_context(dc)) == 0) {
    out = sass_context_get_output_string(c);
    if (out) {
      fprintf(stdout, "%s", out);
    }
  } else {
    out = sass_context_get_error_message(c);
    if (out) {
      fprintf(stderr, "error(%d): %s", rc, out);
    }
  }
  sass_delete_data_context(dc);
  return rc;
}

