#include <iostream>
#include <stdexcept> 
#include <cmath>
#include "AudioProcessor.h"

using namespace std;

vector<short> AudioProcessor::Compress(const std::vector<short>& audio, short threshold, float rate)
{
  if(audio.size()==0) return audio;
  if(threshold < 0 || rate < 1.0)
      throw invalid_argument("Invalid value.");
  else
  {
      for(int i=0; i<audio.size(); i++)
      {
         if(audio[i] <= threshold && audio[i] >= (-1)*threshold)
            compAudio.push_back(audio[i]);
         else
         {
            if(audio[i] >= 0)
            {
                numsamp=(audio[i] - threshold)/rate + threshold;
                short x=round(numsamp);
                compAudio.push_back(x);
            }
          
            else
            {
                numsamp=(audio[i] + threshold)/rate - threshold;  // when the value is negative, do oppsite formula
                short y=round(numsamp);
                compAudio.push_back(y);
            }          
         }
      }
  }
  return compAudio;
 
}
                  
vector<short> AudioProcessor::CutOutSilence(const std::vector<short> & audio, short level, int silenceLength)
{
  if(level<0 || silenceLength<1)
      throw invalid_argument("Invalid value of level or silenceLength.");
  if(audio.size()==0) return audio;
  vector<short> memo;
  for(int i=0; i<audio.size(); i++)
  {
      if (abs(audio[i])<= level)
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
                   memo.push_back(audio[j]);
         }
      }
      if(abs(audio[i])>level)
           memo.push_back(audio[i]);
    }
  
  return memo;
}

vector<short> AudioProcessor::StretchTwice(const std::vector<short>& audio)
{
  if(audio.size()<2) return audio;
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
  if(audio.size()==0) return audio;
  
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
