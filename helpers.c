// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int f; 
    f = ( 8 / (fraction[2] - '0') ) * (fraction[0] - '0');
    return f;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    double freq = 440;
    int size = strlen(note);
    double notePowerIndex = 0;
    
    // calculating 'base note' power index
    switch ( note[0] ) {
        case 'A': 
            notePowerIndex = 0;
            break;
        case 'B': 
            notePowerIndex = 2;
            break;
        case 'C': 
            notePowerIndex = 3;
            break;
        case 'D': 
            notePowerIndex = 5;
            break;
        case 'E': 
            notePowerIndex = 7;
            break;
        case 'F': 
            notePowerIndex = 8;
            break;
        case 'G': 
            notePowerIndex = 10;
            break;
        default:
            break;
    }

    // support for '#' and 'b'
    if ( size == 3 )
    {
        if ( note[1] == '#' )
        {
            notePowerIndex++;
        } else
        if ( note[1] == 'b' )
        {
            notePowerIndex--;
        }
    }

    // octave support
    int defOct;
    if ( notePowerIndex < 3 )
    { 
        defOct = 4;
    } else
    { 
        defOct = 5;
    }

    // calculating final power index
    notePowerIndex += (( note[size-1] - '0' ) - defOct) * 12;

    // calculating frequency 
    freq *= pow(2, notePowerIndex/12); 

    return round(freq);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    int size = strlen(s);
    if ( size == 0 ) 
    {
        return true;
    } else 
    if ( s[size - 1] == '\n' )
    {
        return true;
    } else
    if ( s[0] == ' ' )
    {
        return true;
    } else
    if ( size < 4 )
    {
        return true;
    }
    return false;
}
