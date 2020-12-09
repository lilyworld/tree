#ifndef AUDIOPROCESSOR_H
#define	    AUDIOPROCESSOR_H
#include <iostream>
#include <vector>

class AudioProcessor
{
  public:
    /**@@returns the compressed version of the given audio. **/
    //“Compressed” means that any number from audio that is larger than threshold or smaller
    // than -threshold has it’s “above the threshold” portion reduced rate time.
    std::vector<short> Compress(const std::vector<short>& audio, short threshold, float rate); 
  
    /**@@returns the version of audio where all silences of at least silenceLength length are removed.**/
    std::vector<short> CutOutSilence(const std::vector<short>& audio, short level, int silenceLength);
  
    /**@@Returns the version of audio where between each pair of original samples from audio an extra sample appears.**/
    std::vector<short> StretchTwice(const std::vector<short>& audio);
  
    /**@@returns a version of audio where all samples are proportionally increases or decreased to ensure that the
    largest absolute value from all resulting samples is exactly normalizeTarget. **/
    std::vector<short> Normalize(const std::vector<short>& audio, short normalizeTarget);
    
  
  private:
    float numsamp;  //numbers/samples.
  
};

#endif
    
