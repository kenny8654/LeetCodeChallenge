/**
Runtime: 56ms. Beats 98.35%of users with C++.
Memory: 35.78mb. Beats 98.58%of users with C++
  **/
#define BARCODES_NUM_CNT 10001
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> ret(barcodes.size());
        int barcode_cnt[BARCODES_NUM_CNT] = {};
        int max_cnt(0), max_barcode(0), cur(1);
        for(auto& barcode:barcodes){
            barcode_cnt[barcode]++;
            if(barcode_cnt[barcode] > max_cnt){
                max_barcode = barcode;
                max_cnt = barcode_cnt[barcode];
            }
        }

        for(int i=0, num_cnt=0; num_cnt<barcodes.size(); i+=2, num_cnt++){
            if(i >= barcodes.size())
                i = 1;

            if(barcode_cnt[max_barcode] > 0){
                ret[i] = max_barcode;
                barcode_cnt[max_barcode]--;
            }else{
                while(barcode_cnt[cur] == 0){
                    cur++;
                }
                ret[i] = cur;
                barcode_cnt[cur]--;
            }
        }
        return ret;
    }
};
