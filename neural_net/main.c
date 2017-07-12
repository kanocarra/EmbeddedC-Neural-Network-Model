//
//  main.c
//  neural_net
//
//  Created by Emily Melhuish on 8/07/17.
//  Copyright © 2017 Emily Melhuish. All rights reserved.
//

#include <stdio.h>
#include "Layer.h"

enum input{TIME_ELAPSED, VOLTAGE, CURRENT, CAPACITY, INTERNAL_RESISTANCE};
enum nodes{SM1, SM2, SM3};

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    Layer layer1 = init_layer();
    
    long double sigmoid_node1_weights[MAX_INPUTS];
    long double sigmoid_node2_weights[MAX_INPUTS];
    long double sigmoid_node3_weights[MAX_INPUTS];
    long double sigmoid_node1_bias;
    long double sigmoid_node2_bias;
    long double sigmoid_node3_bias;
    
    
    sigmoid_node1_weights[TIME_ELAPSED] = 4.878289914735682;
    sigmoid_node1_weights[VOLTAGE] = 6.353756026857561;
    sigmoid_node1_weights[CURRENT] = 3.407684855151011;
    sigmoid_node1_weights[CAPACITY] = -0.06926945731506193;
    sigmoid_node1_weights[INTERNAL_RESISTANCE] =  -0.010043877987725111;
    sigmoid_node1_bias =  4.742042871760883;
    add_neuron(sigmoid_node1_weights, &layer1, 1, 5, sigmoid_node1_bias);
    
    sigmoid_node2_weights[TIME_ELAPSED] = 1.176881690677296;
    sigmoid_node2_weights[VOLTAGE] =  0.025788514341405753;
    sigmoid_node2_weights[CURRENT] = -0.9214576810041776;
    sigmoid_node2_weights[CAPACITY] =  0.5822346570940141;
    sigmoid_node2_weights[INTERNAL_RESISTANCE] = 0.02865397891804468;
    sigmoid_node2_bias =   -2.9953645011246555;
    add_neuron(sigmoid_node2_weights, &layer1, 1, 5, sigmoid_node2_bias);
    
    sigmoid_node3_weights[TIME_ELAPSED] = 0.2994308683068657;
    sigmoid_node3_weights[VOLTAGE] = 14.855021773095666;
    sigmoid_node3_weights[CURRENT] =  0.8361545963317351;
    sigmoid_node3_weights[CAPACITY] = 0.023966700635398273;
    sigmoid_node3_weights[INTERNAL_RESISTANCE] = 0.001179240596627643;
    sigmoid_node3_bias =  -1.2413421333276302;
    add_neuron(sigmoid_node3_weights, &layer1, 1, 5, sigmoid_node3_bias);
    
    Layer layer2 = init_layer();
    
    long double linear_node0_weights[3];
    long double linear_node0_bias;
    
    linear_node0_weights[SM1] =  1.017107093283043;
    linear_node0_weights[SM2] =   0.7075539003596144;
    linear_node0_weights[SM3] = 1.0182853576502393;
    linear_node0_bias =   -1.0325764534548219;
    add_neuron(linear_node0_weights, &layer2, 0, 5, linear_node0_bias);
    
    long double inputs[5] = {-0.871483, -0.009009, -0.98628, 0.903284, -0.922976};
    Layer* layers[2] = {&layer1, &layer2};
    
    
    long double normalised_soc = compute_result(layers, inputs);
    
    long double soc = (((normalised_soc- -1.0) * 100.0) / 2.0);

    printf("Estimaed SoC: %Lf \n", soc);
    
    return 0;
}
