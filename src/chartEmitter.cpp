#include <iostream>

#include "chartEmitter.h"

namespace FC { namespace BE {

ChartEmitter::ChartEmitter(std::shared_ptr<IR::Stm> tree) : tree(tree) {
    this->boxes.reset(this->tree->Build());
}

void ChartEmitter::attachChartInfo() {
    AttachInfo ainfo = this->boxes->Attach();
    this->chartWidth = ainfo.lWidth + ainfo.rWidth + 1;
    this->boxes->Print(0);

    // init flowchart
    this->flowchart.resize(ainfo.height);
    for (std::vector<char> &row : this->flowchart) {
        row = std::vector<char>(this->chartWidth, ' ');
    }
}

// void ChartEmitter::draw() {
//     this->rowIniter = std::vector<char>(' ', this->chartWidth);
//     // this->flowchart.push_back(this->rowIniter); 
// }
}}