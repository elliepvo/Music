// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO

    // num and denom to integer
    int num = atoi(&fraction[0]);
    int denom = atoi(&fraction[2]);

    // convert num to number of eigths
    int dur = (8 / denom) * num;
    return dur;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
    // get octave from last char in string note

    int octave = note[strlen(note) - 1] - '0';
    // determine freq of note in an octave
    // KNOW: A4 = 440 Hz
    // multiply for every semitone moving UP
    // divide for every semitone moving DOWN
    // by 2 power(1/12)
    // factor in sharps (*freq by 2 power 1/12) and flats (/fre by 2 power 1/12)

    double frequency = 440;


    if (note[0] == 'A' && strlen(note) < 3)
    {
        frequency = 440; // 440*(pow(2.0,(x/12.0)))
    }
    else if (note[0] == 'A' && note[1] == '#')
    {
        frequency = 440 * (pow(2.0, (1.0 / 12.0)));
    }
    else if (note[0] == 'A' && note[1] == 'b')
    {
        frequency = 440 / (pow(2.0, (1.0 / 12.0)));
    }
    else if (note[0] == 'B' && strlen(note) < 3)
    {
        frequency = 440 * (pow(2.0, (2.0 / 12.0)));
    }
    else if (note[0] == 'B' && note[1] == 'b')
    {
        frequency = 440 * (pow(2.0, (1.0 / 12.0)));
    }
    else if (note[0] == 'C' && strlen(note) < 3)
    {
        frequency = 440 / (pow(2.0, (9.0 / 12.0)));
    }
    else if (note[0] == 'C' && note[1] == '#')
    {
        frequency = 440 / (pow(2.0, (8.0 / 12.0)));
    }
    else if (note[0] == 'D' && strlen(note) < 3)
    {
        frequency = 440 / (pow(2.0, (7.0 / 12.0)));
    }
    else if (note[0] == 'D' && note[1] == '#')
    {
        frequency = 440 / (pow(2.0, (6.0 / 12.0)));
    }
    else if (note[0] == 'D' && note[1] == 'b')
    {
        frequency = 440 / (pow(2.0, (8.0 / 12.0)));
    }
    else if (note[0] == 'E')
    {
        frequency = 440 / (pow(2.0, (5.0 / 12.0)));
    }
    else if (note[0] == 'E' && note[1] == 'b')
    {
        frequency = 440 / (pow(2.0, (6.0 / 12.0)));
    }
    else if (note[0] == 'F' && strlen(note) < 3)
    {
        frequency = 440 / (pow(2.0, (4.0 / 12.0)));
    }
    else if (note[0] == 'F' && note[1] == '#')
    {
        frequency = 440 / (pow(2.0, (3.0 / 12.0)));
    }
    else if (note[0] == 'G' && strlen(note) < 3)
    {
        frequency = 440 / (pow(2.0, (2.0 / 12.0)));
    }
    else if (note[0] == 'G' && note[1] == '#')
    {
        frequency = 440 / (pow(2.0, (1.0 / 12.0)));
    }
    else if (note[0] == 'G' && note[1] == 'b')
    {
        frequency = 440 / (pow(2.0, (3.0 / 12.0)));
    }

    // chars : ABCDEFG = 12 semitones w/ accidentals + flats
    // distance between A and C = -9
    // Piano layout: C = -9, C# = -8, D = -7, D# = -6, E = -5, F = -4, F3 = -3, G = -2, G# = -1, A = 0, A# = 1, B = 2
    // shift in loop: shift octave

    if (octave > 4)
    {
        for (int i = 0; i < octave - 4; i++)

        {
            frequency *= 2;
        }

    }
    else if (octave < 4)
    {
        for (int i = 0; i < 4 - octave; i++)
        {
            frequency /= 2;
        }
    }

    // return freq as int

    float result = round(frequency);
    return result;
    // use power and round

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO

    if (strcmp(s, "") == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
