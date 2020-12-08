#include <iostream>
#include <stdexcept> 
#include <cmath>
#include "AudioProcessor.h"

using namespace std;

vector<short> AudioProcessor::Compress(const std::vector<short>& audio, short threshold, float rate)
{
  if(threshold < 0 || rate < 1.0)
      throw invalid_argument("Invalid value.");
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
                short x=round(numsamp);
                CompAudio.push_back(x);
            }
          
            else
            {
                numsamp=(audio[i] + threshold)/rate - threshold;  // when the value is negative, do oppsite formula
                short y=round(numsamp);
                CompAudio.push_back(y);
            }          
         }
      }
  }
  return CompAudio;
 
}
                  
vector<short> AudioProcessor::CutOutSilence(const std::vector<short> & audio, short level, int silenceLength)
{
  if(level<0 || silenceLength<1)
      throw invalid_argument("Invalid value of level or silenceLength.");
  int i=0;
  while(i<audio.size())
  {
      if ((audio[i] >= (-level)) && (audio[i] <= level))
      {
         int start = i;
         int length = 0;   // to get length of silence in audio vector
         while (i<audio.size() && abs(audio[i])<=level)
         {
              length++;
              i++;
         }
         if (length < silenceLength)
         {
              for (int j = start; j < i; j++)
              {
                   CompAudio.push_back(audio[j]);
              }
         }
         i--;
      }
      else
           CompAudio.push_back(audio[i]);

      i++;
     }
  return CompAudio;
}

vector<short> AudioProcessor::StretchTwice(const std::vector<short>& audio)
{
  //store the original data, and calculated data
  vector<short> memo;
  for(int i=0; i<audio.size()-1; i++)
  {
    memo.push_back(audio[i]);
    float x = (audio[i]+audio[i+1]) * 0.5;
    short y=round(x);
    memo.push_back(y);

  }
  memo.push_back(audio[audio.size()-1]);  // store the last element
  return memo;
}
  
  
vector<short> AudioProcessor::Normalize(const std::vector<short>& audio, short normalizeTarget)
{
  if (normalizeTarget<1)
      throw invalid_argument("Invalid normalizeTarget value.");
  
  short max=0;
  for(int i=0; i<audio.size(); i++)
  {
      if(max<abs(audio[i]))
          max=abs(audio[i]);
  }

  float mul = (float)normalizeTarget/max;  //turn short into float

  vector<short> memo;
  for(int i=0; i<audio.size(); i++)
  {
      float x=audio[i]*mul;
      short y =round(x);
      memo.push_back(y);
  }
  return memo;
}
