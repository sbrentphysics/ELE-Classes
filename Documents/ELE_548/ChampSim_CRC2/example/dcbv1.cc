

#include "../inc/champsim_crc2.h"
#include <stdlib.h>

#define NUM_CORE 1
#define LLC_SETS NUM_CORE*2048
#define LLC_WAYS 16


uint32_t dcb[LLC_SETS][LLC_WAYS]; // had [NUM_GROUPS] before
uint32_t group_number;
// initialize replacement state
void InitReplacementState()
{
    cout << "Initialize DCB replacement state" << endl;

    for (int i=0; i<LLC_SETS; i++) {
        for (int j=0; j<LLC_WAYS; j++) {
            dcb[i][j] = j % 4;
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
 group_number = (rand() % 4) * 4; //Randomly selecting one of four groups

    for(int i = group_number; i<group_number+4; i++){ //Loops through group numbers
       dcb[set][i] = 3; //group_number-1; //had to fix this, initially had a 3 on rhs but forbids pointer to integer. If the selected victim is on bottom return that index
	return i;
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

// way here is the returned index i from above. 
//below we are indexing again but this time with ints and not remainder.  

 group_number = (way/4)*4;
 
//if it's hit
if(hit == 1){    
    for (uint32_t i=group_number; i<group_number+4; i++) {
        if (dcb[set][i] == 0) {  //if hit is true and hit block is at the top, let it stay there
             //dcb[set][i]++;
        } 
	dcb[set][i]==dcb[set][i-1];
      dcb[set][i-1]==dcb[set][i] //set temp var
    } //end of for loop


} //end of hit = true 
// if it isn't hit
 else {
    for (uint32_t i=group_number; i<group_number+4; i++) {
        if (dcb[set][i] > 0) { //if hit is false the top block is removed
            dcb[set][i]--;
        }
    }


} //end of else statement



}

// use this function to print out your own stats on every heartbeat 
void PrintStats_Heartbeat()
{

}

// use this function to print out your own stats at the end of simulation
void PrintStats()
{

}
