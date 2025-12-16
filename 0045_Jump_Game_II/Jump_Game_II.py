# keu hasbi na amar comments pore, ami amar moto psycho ke bhojhanor jonno oi type er comments likhechi

class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        farthest = 0
        curend = 0
        steps = 0
        for i in range(n-1):
            farthest = max(farthest, i + nums[i]) # Track the farthest index reachable from the current jump range
            # Every index inside the current range gets a chance
            # Next iterate e dekhbo highscore bhangche kina, jodi bhange tahole ota FARTHEST hobe nahole ager tai thakbe
            
            
            if i == curend: # Amar check korar jonno egote sujog diyeche current end obdhi jeta kina ager jump er highscore chilo
                steps += 1 # # sob check kora hoyegeche ebar jhap marte hobei
                # One jump taken to move to the next range
                # (kotheke jhap dichi, kothay land korchi, osob to jiges koreni, khali jante cheyeche kota jump
                # Ha ebar compelete hoar por noi ami backtrack tokhun ber korte pari kotha theke jhap mere chilam bole ekhane achi.
                # ota jante chaine so bhebe lavnei. 
                # Ami jekhan theke khusi (limit er bhetor theke) jhap mari na kno obviously jeta te beshi pouchote parbo seta theke jhap merechi mone kore nebo)
                # Tar mane amar maximum jump tai ekhun amar notun limit hobe check korte parar.
                # ekta jhap mere niyechi tarmane ami ekhun next range e
                curend = farthest 
        
        return steps