FILE(REMOVE_RECURSE
  "CMakeFiles/modA.dir/modA.c.o"
  "libmodA.pdb"
  "libmodA.so"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang C)
  INCLUDE(CMakeFiles/modA.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
