#include <bits/stdc++.h>
using namespace std;
class Solution {   
    private:  
    bool checkValidityOfCoordinates(int currentRow,
                                    int currentColumn,
                                    int totalRows,
                                    int totalColumns) {
        
        if(currentRow < 0) {
            return false;
        }
        if(currentColumn < 0) {
            return false;
        }
        if(currentRow >= totalRows) {
            return false;
        }
        if(currentColumn >= totalColumns) {
            return false;
        }
        return true;
    }
    bool isTraversableCell(int rowValue) {   
        if(rowValue == 1) {
            return true;
        }    
        return false;
    }
    void performDepthTraversal(int startingRowIndex,
                               int startingColumnIndex,
                               vector<vector<int>>& matrixGridReference) {
        
        int totalNumberOfRowsPresent =
            (int)matrixGridReference.size(); 
        int totalNumberOfColumnsPresent =
            (int)matrixGridReference[0].size();
        bool isCurrentPositionInsideGrid =
            checkValidityOfCoordinates(startingRowIndex,
                                       startingColumnIndex,
                                       totalNumberOfRowsPresent,
                                       totalNumberOfColumnsPresent);
        
        if(isCurrentPositionInsideGrid == false) {
            return;
        }
        int currentCellValue =
            matrixGridReference[startingRowIndex][startingColumnIndex];
        bool currentPositionCanBeVisited =
            isTraversableCell(currentCellValue);
        if(currentPositionCanBeVisited == false) {
            return;
        }
        matrixGridReference[startingRowIndex][startingColumnIndex] = 2;
        int rowMovementArray[4];
        rowMovementArray[0] = -1;
        rowMovementArray[1] = 1;
        rowMovementArray[2] = 0;
        rowMovementArray[3] = 0;
        int columnMovementArray[4];
        columnMovementArray[0] = 0;
        columnMovementArray[1] = 0;
        columnMovementArray[2] = -1;
        columnMovementArray[3] = 1;
        for(int movementIndex = 0;
            movementIndex < 4;
            movementIndex++) {   
            int nextRowCoordinate =
                startingRowIndex +
                rowMovementArray[movementIndex];
            int nextColumnCoordinate =
                startingColumnIndex +
                columnMovementArray[movementIndex];
            performDepthTraversal(nextRowCoordinate,
                                  nextColumnCoordinate,
                                  matrixGridReference);
        }
    }
    
    public:
    int cntOnes(vector<vector<int>>& grid) { 
        int numberOfRowsInMatrix =
            (int)grid.size();
        int numberOfColumnsInMatrix =
            (int)grid[0].size();
        for(int leftToRightTraversalIndex = 0;
            leftToRightTraversalIndex < numberOfRowsInMatrix;
            leftToRightTraversalIndex++) {
            int firstColumnIndex = 0;
            int lastColumnIndex =
                numberOfColumnsInMatrix - 1;
            performDepthTraversal(leftToRightTraversalIndex,
                                  firstColumnIndex,
                                  grid);
            performDepthTraversal(leftToRightTraversalIndex,
                                  lastColumnIndex,
                                  grid);
        }
        for(int topToBottomTraversalIndex = 0;
            topToBottomTraversalIndex < numberOfColumnsInMatrix;
            topToBottomTraversalIndex++) {
            int firstRowIndex = 0;
            int lastRowIndex =
                numberOfRowsInMatrix - 1;
            performDepthTraversal(firstRowIndex,
                                  topToBottomTraversalIndex,
                                  grid);
            performDepthTraversal(lastRowIndex,
                                  topToBottomTraversalIndex,
                                  grid);
        }
        int finalAnswerToReturn = 0; 
        for(int outerRowLoop = 0;
            outerRowLoop < numberOfRowsInMatrix;
            outerRowLoop++) {               
            for(int innerColumnLoop = 0;
                innerColumnLoop < numberOfColumnsInMatrix;
                innerColumnLoop++) {           
                int currentMatrixCellValue =
                    grid[outerRowLoop][innerColumnLoop];
                if(currentMatrixCellValue == 1) {      
                    finalAnswerToReturn =
                        finalAnswerToReturn + 1;
                }
            }
        }   
        return finalAnswerToReturn;
    }
};