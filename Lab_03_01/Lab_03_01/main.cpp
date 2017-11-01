#include <iostream>

#include "wav_core.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "************** | WavCore | **************" << endl;

    // ################  Tests for WavCore  ################
    const char* input_fname  = "c:\\temp\\0.wav";
    const char* output_fname = "c:\\temp\\out.wav";

	try
	{
		// #### Opening WAV file, checking header.
		WavData sample(input_fname);
		//sample.CreateFromFile(input_fname);

		// #### Printing description.
		cout << sample.GetDescription() << endl;

		// #### Make several changes to PCM data.

		// # Making signal mono from stereo.
		sample.ConvertStereoToMono();

		// # Add a reverberation.
		sample.ApplyReverb(0.5, 0.6f);

		// #### Making new WAV file using edited PCM data.
		sample.SaveToFile(output_fname);

		cout << sample.GetDescription() << endl;

		int sampleRate = sample.GetSampleRate();
		int chanCount = sample.GetChanCount();
		bool isStereo = sample.IsStereo();
	}
	catch (exceptions& e)
	{
		cout << e.out() << endl;
	}
    return 0;
}
