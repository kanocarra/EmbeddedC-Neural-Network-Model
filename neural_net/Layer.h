//
//  Layer.h
//  neural_net
//
//  Created by Emily Melhuish on 8/07/17.
//  Copyright © 2017 Emily Melhuish. All rights reserved.
//

#ifndef Layer_h
#define Layer_h

#include <stdio.h>
#include "Neuron.h"

#define MAX_NEURONS 10
#define N_LAYERS 2

typedef struct{
    Neuron neurons[MAX_NEURONS];
    int next_index;
}Layer;

Layer init_layer(void);
void add_neuron(long double weights[MAX_INPUTS], Layer* layer, bool is_sigmoid, int n_inputs, long double bias);
long double compute_result(Layer* layers[N_LAYERS], long double inputs[MAX_INPUTS]);



#endif /* Layer_h */
