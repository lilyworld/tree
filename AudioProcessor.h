#ifndef AUDIOPROCESSOR_H
#define	AUDIOPROCESSOR_H
#include <iostream>
#incldue <vector>

class AudioProcessor
{
  pubilc:
    std::vector Compress(const std::vector & audio, short threshold, float rate);
    std::vector CutOutSilence(const std::vector & audio, short level, int silenceLength);
    std::vector StretchTwice(const std::vector & audio);
    std::vector Normalize(const std::vector & audio, short normalizeTarget);
    
  
  
  
  
  
  
  
};

#endif
    
