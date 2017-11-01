#pragma once

#include <vector>
#include <string>
#include "wav_header.h"
#include "exceptions.h"

// TODO: Make support for 8-bit PSM, not just 16-bit.
// TODO: Write a function to change the tone of the voice. (Interestingly, it's not too difficult?)

// *********************************************************************
// * Error handling
// *********************************************************************

class WavData {
public:
	//Constructors
	WavData() {};
	WavData(const char* filename);

	// ************************************************************************
	// * Functions for working with WAV file
	// ************************************************************************

	// Reads file 'filename' and puts PCM data (raw sound data) to 'channels_data'.
	// Also checks header validity
	void CreateFromFile(const char* filename);

	// Reads file 'filename' and puts header's data to 'header_ptr' address.
	// Also checks header validity
	void read_header(const char* filename);

	// Prints header's data
	void addToStr(std::string& in, std::string in2, unsigned long num);
	std::string GetDescription();

	// Creates a new WAV file 'filename', using 'sample_rate' and PCM data from 'channels_data'.
	void SaveToFile(const char* filename);

	// ************************************************************************
	// * Functions for working with sound PCM data - Digital Signal Processing
	// ************************************************************************

	// Makes mono PCM data from stereo 'source'.
	void ConvertStereoToMono();

	// Adds a reverberation (it's like an echo).
	void ApplyReverb(double delay_seconds, float decay);

	// Return info about file
	int GetSampleRate();
	int GetChanCount();
	bool IsStereo();

private:

	wav_header_s header;
	std::vector<std::vector<short>> channels_data;

	// ************************************************************************
	// * Private functions
	// ************************************************************************

	// Fills header with zeroes.
	void null_header();

	// Checks header validity.
	void check_header(size_t file_size_bytes);

	// Fills header information, using input parameters. This function calls prefill_header() itself.
	void fill_header(int chan_count, int bits_per_sample, int sample_rate, int samples_count_per_chan);

	// Fills 'header_ptr' with default values.
	void prefill_header();

};