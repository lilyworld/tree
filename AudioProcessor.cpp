#include <iostream>
#include <stdexcept> 
#include <cmath>
#include "AudioProcessor.h"
using audio_t = std::vector<short>;
using namespace std;

AudioProcessor::vector Compress(const std::vector & audio, short threshold, float rate)
{
  if(threshold < 0 || rate < 1.0)
      throw invalid_argument exception("Invalid value.")
  else
  {
      for(int i=0; i<audio.size(); i++)
      {
         if(audio[i] <= threshold && audio[i] >= (-1)*threshold)
            CompAudio.push_back(audio[i]);
         else
         {
            if(audio[i] >= 0)
            {
                numsamp=(audio[i] - threshold)/rate + threshold;
                round(numsamp);
                CompAudio.push_back(numsamp);
            }
          
            else
            {
                numsamp=(audio[i] + threshold)/rate - threshold;
                round(numsamp);
                CompAudio.push_back(numsamp);
            }          
         }
      }
  }
  return CompAudio;
 
}
                  
AudioProcessor::vector CutOutSilence(const std::vector & audio, short level, int silenceLength)
{
  for(int i=0; i<audio.size(); i++)
  {
    if(audio[i] > level || audio[i] < (-1)*level)
        CompAudio.push_back(audio[i]);
  }
  return CompAudio;
}

AudioProcessor::vector StretchTwice(const std::vector & audio)
{
  CompAudio = audio;
  
AudioProcessor::vector Normalize(const std::vector & audio, short normalizeTarget);
