/*
Runtime: 0 ms, Beats: 100%
Memory: 6.1 MB, Beats: 81.26%
*/
class Solution {
private:
    const int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; //n,e,s,w
    int dir = 0;
public:
    bool isRobotBounded(string instructions) {
        int i = 0, j = 0;
        run_instructions(instructions, i, j);
        if(i == 0 && j == 0)
            return true;
        run_instructions(instructions, i, j);
        if(i == 0 && j == 0)
            return true;
        run_instructions(instructions, i, j);
        run_instructions(instructions, i, j);
        if(i == 0 && j == 0)
            return true;
        return false;
    }
    void run_instructions(string &instructions,int &i, int &j){
        for(auto& instruction:instructions)
        switch(instruction){
            case 'G':
                i += dirs[dir][0];
                j += dirs[dir][1];
                break;
            case 'L':
                dir = (dir - 1 + 4) % 4;
                break;
            case 'R':
                dir = (dir + 1 + 4) % 4;
                break;
        }
    }
};
