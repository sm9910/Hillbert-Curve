
#include "hilbert.h"
#include <iostream>
#include <bits/stdc++.h> 

HilbertCurve::HilbertCurve(int level, int size): turtle(size,size){
    unordered_map<hilbert_t, const InstructionList*> umap;
    InstructionList odd, even;
    double distance;
    
    rules.append(TURN_LEFT);
    rules.append(EVEN);
    rules.append(FORWARD);
    rules.append(TURN_RIGHT);
    rules.append(ODD);
    rules.append(FORWARD);
    rules.append(ODD);
    rules.append(TURN_RIGHT);
    rules.append(FORWARD);
    rules.append(EVEN);
    rules.append(TURN_LEFT);
    
    odd.append(TURN_LEFT);
    odd.append(EVEN);
    odd.append(FORWARD);
    odd.append(TURN_RIGHT);
    odd.append(ODD);
    odd.append(FORWARD);
    odd.append(ODD);
    odd.append(TURN_RIGHT);
    odd.append(FORWARD);
    odd.append(EVEN);
    odd.append(TURN_LEFT);
    
    even.append(TURN_RIGHT);
    even.append(ODD);
    even.append(FORWARD);
    even.append(TURN_LEFT);
    even.append(EVEN);
    even.append(FORWARD);
    even.append(EVEN);
    even.append(TURN_LEFT);
    even.append(FORWARD);
    even.append(ODD);
    even.append(TURN_RIGHT);
    
    umap[ODD]= &odd;
    umap[EVEN] = &even;
    

   
    for(int i = 1; i < level; i++){
      rules.substitute(umap);
    }
    
    distance = size/pow(2, level);
    rules.setDistance(distance);
    
    turtle.follow(rules);
    
}
