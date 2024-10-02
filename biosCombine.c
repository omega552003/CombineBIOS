// Combine split Hi/LO BIOS binaries into one binary file.
// Original code posted by jakethompson1 on the VOGONS forum
// Link: https://www.vogons.org/viewtopic.php?p=1082987#p1082987
// License: Creative Commons Attribution 4.0 International
//          https://spdx.org/licenses/CC-BY-4.0.html#licenseText

#include <stdio.h>

int main(int argc, char *argv[])
{
   FILE *fLow, *fHigh, *fOut;
   int c;
  
   if (argc != 4)
   {
      fputs("usage: merge low.bin high.bin out.bin\n", stderr);
      return -1;
   }
   fLow = fopen(argv[1], "rb");
   if (!fLow)
   {
      perror(argv[1]);
      return -1;
   }
   fHigh = fopen(argv[2], "rb");
   if (!fHigh)
   {
      perror(argv[2]);
      return -1;
   }
   fOut = fopen(argv[3], "rb");
   if (fOut)
   {
      fprintf(stderr, "%s already exists!\n", argv[3]);
      return -1;
   }
   fOut = fopen(argv[3], "wb");
   if (!fOut)
   {
      perror(argv[3]);
      return -1;
   }

   while ((c = getc(fLow)) != EOF)
   {
      putc(c, fOut);
      c = getc(fHigh);
      if (c == EOF)
	 break;
      putc(c, fOut);
   }
   fclose(fLow);
   fclose(fHigh);
   fclose(fOut);
   return 0;
}