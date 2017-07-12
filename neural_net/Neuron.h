//
//  Neuron.h
//  neural_net
//
//  Created by Emily Melhuish on 8/07/17.
//  Copyright © 2017 Emily Melhuish. All rights reserved.
//

#ifndef Neuron_h
#define Neuron_h

#define MAX_INPUTS 5

#include <stdio.h>
#include<stdbool.h>

typedef struct{
    long double weights[MAX_INPUTS];
    int n_inputs;
    bool is_sigmoid;
    long double bias;
}Neuron;

Neuron init_neuron(long double in_weights[MAX_INPUTS], bool in_is_sigmoid, int n_inputs, long double bias);
void set_weights(long double in_weights[MAX_INPUTS], Neuron* neuron);
long double* get_weights(Neuron* neuron);
long double compute_output(Neuron* neuron, long double inputs[MAX_INPUTS]);



#endif /* Neuron_h */
