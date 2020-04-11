#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


// WAV header spec information:
//https://web.archive.org/web/20140327141505/https://ccrma.stanford.edu/courses/422/projects/WaveFormat/
//http://www.topherlee.com/software/pcm-tut-wavformat.html

typedef struct wav_header {
    // RIFF Header
    char riff_header[4]; // Contains "RIFF"
    uint32_t wav_size; // Size of the wav portion of the file, which follows the first 8 bytes. File size - 8
    char wave_header[4]; // Contains "WAVE"

    // Format Header
    char fmt_header[4]; // Contains "fmt " (includes trailing space)
    uint32_t fmt_chunk_size; // Should be 16 for PCM
    uint16_t audio_format; // Should be 1 for PCM. 3 for IEEE Float
    uint16_t num_channels;
    uint32_t sample_rate;
    uint32_t byte_rate; // Number of bytes per second. sample_rate * num_channels * Bytes Per Sample
    uint16_t sample_alignment; // num_channels * Bytes Per Sample
    uint16_t bit_depth; // Number of bits per sample

    // Data
    char data_header[4]; // Contains "data"
    uint16_t data_bytes; // Number of bytes in data. Number of samples * num_channels * sample byte size
    // uint8_t bytes[]; // Remainder of wave file is bytes
} wav_header;

int main (int argc, char *argv[]) {
    if (argc != 2){
        fprintf(stderr, "usage: %s FILE\n", argv[0]);
        return 1;
    }    

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1){
        perror("open");
        return -1;
    }
    wav_header wav = {0};

    read(fd, &wav, sizeof(wav_header));
    close(fd);

    write(STDOUT_FILENO, wav.wave_header, 4);
    write(STDOUT_FILENO, ": ", 2);
    printf("%"PRIu16", %"PRIu32 ", %"PRIu16"\n", wav.num_channels, wav.sample_rate, wav.bit_depth);

    return 0;
}
