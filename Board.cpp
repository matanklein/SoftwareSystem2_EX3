/*
   email- matank214@gmail.com
*/

#include "Board.hpp"

Board::Board()
{
    /*boardPath = {
        {0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    }; */

    boardCross = {Cross(), Cross(), Cross(),
                Cross(), Cross(), Cross(), Cross(),
                Cross(), Cross(), Cross(), Cross(),
            Cross(), Cross(), Cross(), Cross(), Cross(),
            Cross(), Cross(), Cross(), Cross(), Cross(),
        Cross(), Cross(), Cross(), Cross(), Cross(), Cross(),
        Cross(), Cross(), Cross(), Cross(), Cross(), Cross(),
            Cross(), Cross(), Cross(), Cross(), Cross(),
            Cross(), Cross(), Cross(), Cross(), Cross(),
                Cross(), Cross(), Cross(), Cross(),
                Cross(), Cross(), Cross(), Cross(),
                  Cross(), Cross(), Cross()
    };

    //boardCross = vector<Cross*>(54, new Cross());

    boardCross[0].setData({4, 5}, 1);
    boardCross[1].setData({5, 6}, 2);
    boardCross[2].setData({6, 7}, 3);

    boardCross[3].setData({1, 8}, 4);
    boardCross[4].setData({1, 2, 9}, 5);
    boardCross[5].setData({2, 3, 10}, 6);
    boardCross[6].setData({3, 11}, 7);

    boardCross[7].setData({4, 12, 13}, 8);
    boardCross[8].setData({13, 14, 5}, 9);
    boardCross[9].setData({14, 15, 6}, 10);
    boardCross[10].setData({15, 16, 7}, 11);

    boardCross[11].setData({8, 17}, 12);
    boardCross[12].setData({8, 9, 18}, 13);
    boardCross[13].setData({9, 10, 19}, 14);
    boardCross[14].setData({10, 11, 20}, 15);
    boardCross[15].setData({11, 21}, 16);

    boardCross[16].setData({12, 22, 23}, 17);
    boardCross[17].setData({23, 23, 13}, 18);
    boardCross[18].setData({23, 25, 14}, 19);
    boardCross[19].setData({25, 26, 15}, 20);
    boardCross[20].setData({26, 27, 16}, 21);

    boardCross[21].setData({17, 28}, 22);
    boardCross[22].setData({17, 18, 29}, 23);
    boardCross[23].setData({18, 19, 30}, 24);
    boardCross[24].setData({19, 20, 31}, 25);
    boardCross[25].setData({20, 21, 32}, 26);
    boardCross[26].setData({21, 33}, 27);

    boardCross[27].setData({34, 22}, 28);
    boardCross[28].setData({34, 35, 23}, 29);
    boardCross[29].setData({35, 36, 23}, 30);
    boardCross[30].setData({36, 37, 25}, 31);
    boardCross[31].setData({37, 38, 26}, 32);
    boardCross[32].setData({38, 27}, 33);

    boardCross[33].setData({28, 39, 29}, 34);
    boardCross[34].setData({29, 30, 40}, 35);
    boardCross[35].setData({30, 31, 41}, 36);
    boardCross[36].setData({31, 32, 42}, 37);
    boardCross[37].setData({32, 33, 43}, 38);

    boardCross[38].setData({44, 34}, 39);
    boardCross[39].setData({44, 45, 35}, 40);
    boardCross[40].setData({45, 46, 36}, 41);
    boardCross[41].setData({46, 47, 37}, 42);
    boardCross[42].setData({47,38}, 43);

    boardCross[43].setData({48, 39, 40}, 44);
    boardCross[44].setData({40, 41, 49}, 45);
    boardCross[45].setData({41, 42, 50}, 46);
    boardCross[46].setData({42, 43, 51}, 47);

    boardCross[47].setData({52, 44}, 48);
    boardCross[48].setData({52, 53, 45}, 49);
    boardCross[49].setData({53, 54, 46}, 50);
    boardCross[50].setData({54, 47}, 51);

    boardCross[51].setData({48, 49}, 52);
    boardCross[52].setData({49, 50}, 53);
    boardCross[53].setData({50, 51}, 54);

    // boardPlot = {
    //         Plot(),Plot(),Plot(),
    //     Plot(),Plot(),Plot(),Plot(),
    //   Plot(),Plot(),Plot(),Plot(),Plot(),
    //     Plot(),Plot(),Plot(),Plot(),
    //         Plot(),Plot(),Plot()
    // };

    boardPlot = vector<Plot*>(19, nullptr);
    
    vector <Cross*> plot0 = {&boardCross[0], &boardCross[3], &boardCross[4], &boardCross[7], &boardCross[8], &boardCross[12]};
    vector <Cross*> plot1 = {&boardCross[1], &boardCross[4], &boardCross[5], &boardCross[8], &boardCross[9], &boardCross[13]};
    vector <Cross*> plot2 = {&boardCross[2], &boardCross[5], &boardCross[6], &boardCross[9], &boardCross[10], &boardCross[14]};
    vector <Cross*> plot3 = {&boardCross[7], &boardCross[11], &boardCross[12], &boardCross[16], &boardCross[17], &boardCross[22]};
    vector <Cross*> plot4 = {&boardCross[8], &boardCross[12], &boardCross[13], &boardCross[17], &boardCross[18], &boardCross[23]};
    vector <Cross*> plot5 = {&boardCross[9], &boardCross[13], &boardCross[14], &boardCross[18], &boardCross[19], &boardCross[24]};
    vector <Cross*> plot6 = {&boardCross[10], &boardCross[14], &boardCross[15], &boardCross[19], &boardCross[20], &boardCross[25]};
    vector <Cross*> plot7 = {&boardCross[16], &boardCross[21], &boardCross[22], &boardCross[27], &boardCross[28], &boardCross[33]};
    vector <Cross*> plot8 = {&boardCross[17], &boardCross[22], &boardCross[23], &boardCross[28], &boardCross[29], &boardCross[34]};
    vector <Cross*> plot9 = {&boardCross[18], &boardCross[23], &boardCross[24], &boardCross[29], &boardCross[30], &boardCross[35]};
    vector <Cross*> plot10 = {&boardCross[19], &boardCross[24], &boardCross[25], &boardCross[30], &boardCross[31], &boardCross[36]};
    vector <Cross*> plot11 = {&boardCross[20], &boardCross[25], &boardCross[26], &boardCross[31], &boardCross[32], &boardCross[37]};
    vector <Cross*> plot12 = {&boardCross[28], &boardCross[33], &boardCross[34], &boardCross[38], &boardCross[39], &boardCross[43]};
    vector <Cross*> plot13 = {&boardCross[29], &boardCross[34], &boardCross[35], &boardCross[39], &boardCross[40], &boardCross[44]};
    vector <Cross*> plot14 = {&boardCross[30], &boardCross[35], &boardCross[36], &boardCross[40], &boardCross[41], &boardCross[45]};
    vector <Cross*> plot15 = {&boardCross[31], &boardCross[36], &boardCross[37], &boardCross[41], &boardCross[42], &boardCross[46]};
    vector <Cross*> plot16 = {&boardCross[39], &boardCross[43], &boardCross[44], &boardCross[47], &boardCross[48], &boardCross[51]};
    vector <Cross*> plot17 = {&boardCross[40], &boardCross[44], &boardCross[45], &boardCross[48], &boardCross[49], &boardCross[52]};
    vector <Cross*> plot18 = {&boardCross[41], &boardCross[45], &boardCross[46], &boardCross[49], &boardCross[50], &boardCross[53]};

    for (int i = 0; i < 19; ++i) {
        boardPlot[i] = new Plot(); // Assuming Plot has a default constructor
    }

    boardPlot[0]->setData(numberInResources[0], typeInPlots[0], plot0);
    boardPlot[1]->setData(numberInResources[1], typeInPlots[1], plot1);
    boardPlot[2]->setData(numberInResources[2], typeInPlots[2], plot2);

    boardPlot[3]->setData(numberInResources[3], typeInPlots[3], plot3);
    boardPlot[4]->setData(numberInResources[4], typeInPlots[4], plot4);
    boardPlot[5]->setData(numberInResources[5], typeInPlots[5], plot5);
    boardPlot[6]->setData(numberInResources[6], typeInPlots[6], plot6);

    boardPlot[7]->setData(numberInResources[7], typeInPlots[7], plot7);
    boardPlot[8]->setData(numberInResources[8], typeInPlots[8], plot8);
    boardPlot[9]->setData(numberInResources[9], typeInPlots[9], plot9);
    boardPlot[10]->setData(numberInResources[10], typeInPlots[10], plot10);
    boardPlot[11]->setData(numberInResources[11], typeInPlots[11], plot11);

    boardPlot[12]->setData(numberInResources[12], typeInPlots[12], plot12);
    boardPlot[13]->setData(numberInResources[13], typeInPlots[13], plot13);
    boardPlot[14]->setData(numberInResources[14], typeInPlots[14], plot14);
    boardPlot[15]->setData(numberInResources[15], typeInPlots[15], plot15);

    boardPlot[16]->setData(numberInResources[16], typeInPlots[16], plot16);
    boardPlot[17]->setData(numberInResources[17], typeInPlots[17], plot17);
    boardPlot[18]->setData(numberInResources[18], typeInPlots[18], plot18);

    

    boardPath = vector<vector<int>>(54, vector<int>(54, noneP));
}

Board::~Board()
{
    for (int i = 0; i < 19; ++i) {
        delete boardPlot[i];
    }
}
