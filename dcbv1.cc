////////////////////////////////////////////
//                                        //
//        LRU replacement policy          //
//     Jinchun Kim, cienlux@tamu.edu      //
//                                        //
////////////////////////////////////////////

#include "../inc/champsim_crc2.h"
#include <stdlib.h>

#define NUM_CORE 1
#define LLC_SETS NUM_CORE*2048
#define LLC_WAYS 16
#define NUM_GROUPS 4

uint32_t dcb[LLC_SETS][LLC_WAYS][NUM_GROUPS];
//uint32_t set_hit_flag[2]; //can either be a hit or a miss

// initialize replacement state
void InitReplacementState()
{
    cout << "Initialize DCB replacement state" << endl;

    for (int i=0; i<LLC_SETS; i++) {
        for (int j=0; j<LLC_WAYS; j++) {
            dcb[i][j] = j % NUM_GROUPS;
        }
    }
}

// find replacement victim
// return value should be 0 ~ 15 or 16 (bypass)


uint32_t GetVictimInSet (uint32_t cpu, uint32_t set, const BLOCK *current_set, uint64_t PC, uint64_t paddr, uint32_t type)
{
  /*
    for (int i=0; i<LLC_WAYS; i++)
        if (lru[set][i] == (LLC_WAYS-1))
            return i;

    return 0;
 */
    for(int i = 0; i<NUM_NUM_GROUPS; i++){
       if(set_hit_flag == 0){
 	dcb[set][top block][i] == victim;
	dcb[set][otherblocks +1][i];
       else if(set_hit_flag == 1)
	dcb[set][bottom block][i] == victi
       }
       

    }

}
// called on every cache hit and cache fill



void UpdateReplacementState (uint32_t cpu, uint32_t set, uint32_t way, uint64_t paddr, uint64_t PC, uint64_t victim_addr, uint32_t type, uint8_t hit)
{

    // update lru replacement state
 /*
    for (uint32_t i=0; i<LLC_WAYS; i++) {
        if (lru[set][i] < lru[set][way]) {
            lru[set][i]++;

            if (lru[set][i] == LLC_WAYS)
                assert(0);
        }
    }
    lru[set][way] = 0; // promote to the MRU position
*/
 for(uint32_t i=0; i<NUM_GROUPS; i++) {
    if(hit == 1){
      if(dcb[set][way][i] > 0){
        if(dcb[set][way][i] == dcb[set][way][i]-1)
          dcb[set][way][i]++;
	
      }
     dcb[set][way][i]--;

    } else{
      if(dcb[set][way][i] == 0){
	dcb[set][way][i]--
      }

  dcb[set][way][i] = 3; // insert incoming block at the bottom of the queue
 }


}

// use this function to print out your own stats on every heartbeat 
void PrintStats_Heartbeat()
{

}

// use this function to print out your own stats at the end of simulation
void PrintStats()
{

}
