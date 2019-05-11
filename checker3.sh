#!/bin/sh

# Define variables
i=0
wins=0
error=0
limit=5
login="psentilh"
champion=`echo ${login:0:1} | tr  '[a-z]' '[A-Z]'`${login:1}

# Define color variables
NC='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'

# List of checks
if [ ! -f "$login.filler" ]; then echo "${RED}$champion file does not exist${NC}" && erroor=1; fi
if [ ! -d "resources" ]; then echo "${RED}resources folder does not exist${NC}" && erroor=1; fi
if [ ! -f "resources/filler_vm" ]; then echo "${RED}resources/filler_vm file does not exist${NC}" && erroor=1; fi
if [ ! -d "resources/maps" ]; then echo "${RED}resources/maps folder does not exist${NC}" && erroor=1; fi
if [ ! -d "resources/players" ]; then echo "${RED}resources/players folder does not exist${NC}" && erroor=1; fi
if [ ! -f "resources/maps/map00" ]; then echo "${RED}resources/maps/map00 file does not exist${NC}" && erroor=1; fi
if [ ! -f "resources/maps/map01" ]; then echo "${RED}resources/maps/map01 file does not exist${NC}" && erroor=1; fi
if [ ! -f "resources/maps/map02" ]; then echo "${RED}resources/maps/map02 file does not exist${NC}" && erroor=1; fi
if [ ! -f "resources/players/abanlin.filler" ]; then echo "${RED}resources/players/abanlin.filler file does not exist${NC}" && erroor=1; fi
if [ ! -f "resources/players/carli.filler" ]; then echo "${RED}resources/players/carli.filler file does not exist${NC}" && erroor=1; fi
if [ ! -f "resources/players/champely.filler" ]; then echo "${RED}resources/players/champely.filler file does not exist${NC}" && erroor=1; fi
if [ ! -f "resources/players/grati.filler" ]; then echo "${RED}resources/players/grati.filler file does not exist${NC}" && erroor=1; fi
if [ ! -f "resources/players/hcao.filler" ]; then echo "${RED}resources/players/hcao.filler file does not exist${NC}" && erroor=1; fi
if [ ! -f "resources/players/superjeannot.filler" ]; then echo "${RED}resources/players/superjeannot.filler file does not exist${NC}" && erroor=1; fi
if [ $error == 1 ]; then exit; fi

# Starting tests

# ----------------------------------------------  ABANLIN  ------------------------------------------------------------

    # Testing ABANLIN on map00
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map00 -p1 resources/players/abanlin.filler -p2 ./$login.filler > trace
        enemy=`grep "== O" trace | cut -d: -f2`
        yours=`grep "== X" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}Abanlin vs $champion on map00: $wins/$limit${NC}"; else echo "${GREEN}Abanlin vs $champion on map00: $wins/$limit${NC}"; fi

    # Testing ABANLIN on map01
    i=0
    wins=0
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map01 -p1 resources/players/abanlin.filler -p2 ./$login.filler > trace
        enemy=`grep "== O" trace | cut -d: -f2`
        yours=`grep "== X" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}Abanlin vs $champion on map01: $wins/$limit${NC}"; else echo "${GREEN}Abanlin vs $champion on map01: $wins/$limit${NC}"; fi

    # Testing ABANLIN on map02
    # i=0
    # wins=0
    # while [[ $i -lt $limit ]]
    # do
    #     ./resources/filler_vm -f resources/maps/map02 -p1 resources/players/abanlin.filler -p2 ./$login.filler > trace
    #     enemy=`grep "== O" trace | cut -d: -f2`
    #     yours=`grep "== X" trace | cut -d: -f2`
    #     if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
    #     ((i++))
    # done
    # if [[ $wins -lt 3 ]]; then echo "${RED}Abanlin vs $champion on map02: $wins/$limit${NC}"; else echo "${GREEN}Abanlin vs $champion on map02: $wins/$limit${NC}"; fi

    # Testing ABANLIN on map00
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map00 -p2 resources/players/abanlin.filler -p1 ./$login.filler > trace
        enemy=`grep "== X" trace | cut -d: -f2`
        yours=`grep "== O" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}$champion vs Abanlin on map00: $wins/$limit${NC}"; else echo "${GREEN}$champion vs Abanlin on map00: $wins/$limit${NC}"; fi

    # Testing ABANLIN on map01
    i=0
    wins=0
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map01 -p2 resources/players/abanlin.filler -p1 ./$login.filler > trace
        enemy=`grep "== X" trace | cut -d: -f2`
        yours=`grep "== O" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}$champion vs Abanlin on map01: $wins/$limit${NC}"; else echo "${GREEN}$champion vs Abanlin on map01: $wins/$limit${NC}"; fi

    # Testing ABANLIN on map02
    # i=0
    # wins=0
    # while [[ $i -lt $limit ]]
    # do
    #     ./resources/filler_vm -f resources/maps/map02 -p2 resources/players/abanlin.filler -p1 ./$login.filler > trace
    #     enemy=`grep "== X" trace | cut -d: -f2`
    #     yours=`grep "== O" trace | cut -d: -f2`
    #     if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
    #     ((i++))
    # done
    # if [[ $wins -lt 3 ]]; then echo "${RED}$champion vs Abanlin on map02: $wins/$limit${NC}"; else echo "${GREEN}$champion vs Abanlin on map02: $wins/$limit${NC}";

# ----------------------------------------------  CARLI  ------------------------------------------------------------

    # Testing CARLI on map00
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map00 -p1 resources/players/carli.filler -p2 ./$login.filler > trace
        enemy=`grep "== O" trace | cut -d: -f2`
        yours=`grep "== X" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}Carli vs $champion on map00: $wins/$limit${NC}"; else echo "${GREEN}Carli vs $champion on map00: $wins/$limit${NC}"; fi

    # Testing CARLI on map01
    i=0
    wins=0
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map01 -p1 resources/players/carli.filler -p2 ./$login.filler > trace
        enemy=`grep "== O" trace | cut -d: -f2`
        yours=`grep "== X" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}Carli vs $champion on map01: $wins/$limit${NC}"; else echo "${GREEN}Carli vs $champion on map01: $wins/$limit${NC}"; fi

    # Testing CARLI on map02
    # i=0
    # wins=0
    # while [[ $i -lt $limit ]]
    # do
    #     ./resources/filler_vm -f resources/maps/map02 -p1 resources/players/carli.filler -p2 ./$login.filler > trace
    #     enemy=`grep "== O" trace | cut -d: -f2`
    #     yours=`grep "== X" trace | cut -d: -f2`
    #     if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
    #     ((i++))
    # done
    # if [[ $wins -lt 3 ]]; then echo "${RED}Carli vs $champion on map02: $wins/$limit${NC}"; else echo "${GREEN}Carli vs $champion on map02: $wins/$limit${NC}"; fi

    # Testing CARLI on map00
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map00 -p2 resources/players/carli.filler -p1 ./$login.filler > trace
        enemy=`grep "== X" trace | cut -d: -f2`
        yours=`grep "== O" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}$champion vs Carli on map00: $wins/$limit${NC}"; else echo "${GREEN}$champion vs Carli on map00: $wins/$limit${NC}"; fi

    # Testing CARLI on map01
    i=0
    wins=0
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map01 -p2 resources/players/carli.filler -p1 ./$login.filler > trace
        enemy=`grep "== X" trace | cut -d: -f2`
        yours=`grep "== O" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}$champion vs Carli on map01: $wins/$limit${NC}"; else echo "${GREEN}$champion vs Carli on map01: $wins/$limit${NC}"; fi

    # Testing CARLI on map02
    # i=0
    # wins=0
    # while [[ $i -lt $limit ]]
    # do
    #     ./resources/filler_vm -f resources/maps/map02 -p2 resources/players/carli.filler -p1 ./$login.filler > trace
    #     enemy=`grep "== X" trace | cut -d: -f2`
    #     yours=`grep "== O" trace | cut -d: -f2`
    #     if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
    #     ((i++))
    # done
    # if [[ $wins -lt 3 ]]; then echo "${RED}$champion vs Carli on map02: $wins/$limit${NC}"; else echo "${GREEN}$champion vs Carli on map02: $wins/$limit${NC}"; fi

# ----------------------------------------------  CHAMPELY  ------------------------------------------------------------

    # Testing CHAMPELY on map00
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map00 -p1 resources/players/champely.filler -p2 ./$login.filler > trace
        enemy=`grep "== O" trace | cut -d: -f2`
        yours=`grep "== X" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}Champely vs $champion on map00: $wins/$limit${NC}"; else echo "${GREEN}Champely vs $champion on map00: $wins/$limit${NC}"; fi

    # Testing CHAMPELY on map01
    i=0
    wins=0
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map01 -p1 resources/players/champely.filler -p2 ./$login.filler > trace
        enemy=`grep "== O" trace | cut -d: -f2`
        yours=`grep "== X" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}Champely vs $champion on map01: $wins/$limit${NC}"; else echo "${GREEN}Champely vs $champion on map01: $wins/$limit${NC}"; fi

    # Testing CHAMPELY on map02
    # i=0
    # wins=0
    # while [[ $i -lt $limit ]]
    # do
    #     ./resources/filler_vm -f resources/maps/map02 -p1 resources/players/champely.filler -p2 ./$login.filler > trace
    #     enemy=`grep "== O" trace | cut -d: -f2`
    #     yours=`grep "== X" trace | cut -d: -f2`
    #     if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
    #     ((i++))
    # done
    # if [[ $wins -lt 3 ]]; then echo "${RED}Champely vs $champion on map02: $wins/$limit${NC}"; else echo "${GREEN}Champely vs $champion on map02: $wins/$limit${NC}"; fi

    # Testing CHAMPELY on map00
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map00 -p2 resources/players/champely.filler -p1 ./$login.filler > trace
        enemy=`grep "== X" trace | cut -d: -f2`
        yours=`grep "== O" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}$champion vs Champely on map00: $wins/$limit${NC}"; else echo "${GREEN}$champion vs Champely on map00: $wins/$limit${NC}"; fi

    # Testing CHAMPELY on map01
    i=0
    wins=0
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map01 -p2 resources/players/champely.filler -p1 ./$login.filler > trace
        enemy=`grep "== X" trace | cut -d: -f2`
        yours=`grep "== O" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}$champion vs Champely on map01: $wins/$limit${NC}"; else echo "${GREEN}$champion vs Champely on map01: $wins/$limit${NC}"; fi

    # Testing CHAMPELY on map02
    # i=0
    # wins=0
    # while [[ $i -lt $limit ]]
    # do
    #     ./resources/filler_vm -f resources/maps/map02 -p2 resources/players/champely.filler -p1 ./$login.filler > trace
    #     enemy=`grep "== X" trace | cut -d: -f2`
    #     yours=`grep "== O" trace | cut -d: -f2`
    #     if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
    #     ((i++))
    # done
    # if [[ $wins -lt 3 ]]; then echo "${RED}$champion vs Champely on map02: $wins/$limit${NC}"; else echo "${GREEN}$champion vs Champely on map02: $wins/$limit${NC}"; fi


# ----------------------------------------------  GRATI  ------------------------------------------------------------

    # Testing GRATI on map00
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map00 -p1 resources/players/grati.filler -p2 ./$login.filler > trace
        enemy=`grep "== O" trace | cut -d: -f2`
        yours=`grep "== X" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}Grati vs $champion on map00: $wins/$limit${NC}"; else echo "${GREEN}Grati vs $champion on map00: $wins/$limit${NC}"; fi

    # Testing GRATI on map01
    i=0
    wins=0
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map01 -p1 resources/players/grati.filler -p2 ./$login.filler > trace
        enemy=`grep "== O" trace | cut -d: -f2`
        yours=`grep "== X" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}Grati vs $champion on map01: $wins/$limit${NC}"; else echo "${GREEN}Grati vs $champion on map01: $wins/$limit${NC}"; fi

    # Testing GRATI on map02
    # i=0
    # wins=0
    # while [[ $i -lt $limit ]]
    # do
    #     ./resources/filler_vm -f resources/maps/map02 -p1 resources/players/grati.filler -p2 ./$login.filler > trace
    #     enemy=`grep "== O" trace | cut -d: -f2`
    #     yours=`grep "== X" trace | cut -d: -f2`
    #     if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
    #     ((i++))
    # done
    # if [[ $wins -lt 3 ]]; then echo "${RED}Grati vs $champion on map02: $wins/$limit${NC}"; else echo "${GREEN}Grati vs $champion on map02: $wins/$limit${NC}"; fi

    # Testing GRATI on map00
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map00 -p2 resources/players/grati.filler -p1 ./$login.filler > trace
        enemy=`grep "== X" trace | cut -d: -f2`
        yours=`grep "== O" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}$champion vs Grati on map00: $wins/$limit${NC}"; else echo "${GREEN}$champion vs Grati on map00: $wins/$limit${NC}"; fi

    # Testing GRATI on map01
    i=0
    wins=0
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map01 -p2 resources/players/grati.filler -p1 ./$login.filler > trace
        enemy=`grep "== X" trace | cut -d: -f2`
        yours=`grep "== O" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}$champion vs Grati on map01: $wins/$limit${NC}"; else echo "${GREEN}$champion vs Grati on map01: $wins/$limit${NC}"; fi

    # Testing GRATI on map02
    # i=0
    # wins=0
    # while [[ $i -lt $limit ]]
    # do
    #     ./resources/filler_vm -f resources/maps/map02 -p2 resources/players/grati.filler -p1 ./$login.filler > trace
    #     enemy=`grep "== X" trace | cut -d: -f2`
    #     yours=`grep "== O" trace | cut -d: -f2`
    #     if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
    #     ((i++))
    # done
    # if [[ $wins -lt 3 ]]; then echo "${RED}$champion vs Grati on map02: $wins/$limit${NC}"; else echo "${GREEN}$champion vs Grati on map02: $wins/$limit${NC}"; fi

# ----------------------------------------------  HCAO  ------------------------------------------------------------

    # Testing HCAO on map00
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map00 -p1 resources/players/hcao.filler -p2 ./$login.filler > trace
        enemy=`grep "== O" trace | cut -d: -f2`
        yours=`grep "== X" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}Hcao vs $champion on map00: $wins/$limit${NC}"; else echo "${GREEN}Hcao vs $champion on map00: $wins/$limit${NC}"; fi

    # Testing HCAO on map01
    i=0
    wins=0
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map01 -p1 resources/players/hcao.filler -p2 ./$login.filler > trace
        enemy=`grep "== O" trace | cut -d: -f2`
        yours=`grep "== X" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}Hcao vs $champion on map01: $wins/$limit${NC}"; else echo "${GREEN}Hcao vs $champion on map01: $wins/$limit${NC}"; fi

    # Testing HCAO on map02
    # i=0
    # wins=0
    # while [[ $i -lt $limit ]]
    # do
    #     ./resources/filler_vm -f resources/maps/map02 -p1 resources/players/hcao.filler -p2 ./$login.filler > trace
    #     enemy=`grep "== O" trace | cut -d: -f2`
    #     yours=`grep "== X" trace | cut -d: -f2`
    #     if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
    #     ((i++))
    # done
    # if [[ $wins -lt 3 ]]; then echo "${RED}Hcao vs $champion on map02: $wins/$limit${NC}"; else echo "${GREEN}Hcao vs $champion on map02: $wins/$limit${NC}"; fi

    # Testing HCAO on map00
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map00 -p2 resources/players/hcao.filler -p1 ./$login.filler > trace
        enemy=`grep "== X" trace | cut -d: -f2`
        yours=`grep "== O" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}$champion vs Hcao on map00: $wins/$limit${NC}"; else echo "${GREEN}$champion vs Hcao on map00: $wins/$limit${NC}"; fi

    # Testing HCAO on map01
    i=0
    wins=0
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map01 -p2 resources/players/hcao.filler -p1 ./$login.filler > trace
        enemy=`grep "== X" trace | cut -d: -f2`
        yours=`grep "== O" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}$champion vs Hcao on map01: $wins/$limit${NC}"; else echo "${GREEN}$champion vs Hcao on map01: $wins/$limit${NC}"; fi

    # Testing HCAO on map02
    # i=0
    # wins=0
    # while [[ $i -lt $limit ]]
    # do
    #     ./resources/filler_vm -f resources/maps/map02 -p2 resources/players/hcao.filler -p1 ./$login.filler > trace
    #     enemy=`grep "== X" trace | cut -d: -f2`
    #     yours=`grep "== O" trace | cut -d: -f2`
    #     if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
    #     ((i++))
    # done
    # if [[ $wins -lt 3 ]]; then echo "${RED}$champion vs Hcao on map02: $wins/$limit${NC}"; else echo "${GREEN}$champion vs Hcao on map02: $wins/$limit${NC}"; fi

# ----------------------------------------------  SUPERJEANNOT  ------------------------------------------------------------

    # Testing SUPERJEANNOT on map00
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map00 -p1 resources/players/superjeannot.filler -p2 ./$login.filler > trace
        enemy=`grep "== O" trace | cut -d: -f2`
        yours=`grep "== X" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}Superjeannot vs $champion on map00: $wins/$limit${NC}"; else echo "${GREEN}Superjeannot vs $champion on map00: $wins/$limit${NC}"; fi

    # Testing SUPERJEANNOT on map01
    i=0
    wins=0
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map01 -p1 resources/players/superjeannot.filler -p2 ./$login.filler > trace
        enemy=`grep "== O" trace | cut -d: -f2`
        yours=`grep "== X" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}Superjeannot vs $champion on map01: $wins/$limit${NC}"; else echo "${GREEN}Superjeannot vs $champion on map01: $wins/$limit${NC}"; fi

    # Testing SUPERJEANNOT on map02
    # i=0
    # wins=0
    # while [[ $i -lt $limit ]]
    # do
    #     ./resources/filler_vm -f resources/maps/map02 -p1 resources/players/superjeannot.filler -p2 ./$login.filler > trace
    #     enemy=`grep "== O" trace | cut -d: -f2`
    #     yours=`grep "== X" trace | cut -d: -f2`
    #     if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
    #     ((i++))
    # done
    # if [[ $wins -lt 3 ]]; then echo "${RED}Superjeannot vs $champion on map02: $wins/$limit${NC}"; else echo "${GREEN}Superjeannot vs $champion on map02: $wins/$limit${NC}"; fi

    # Testing SUPERJEANNOT on map00
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map00 -p2 resources/players/superjeannot.filler -p1 ./$login.filler > trace
        enemy=`grep "== X" trace | cut -d: -f2`
        yours=`grep "== O" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}$champion vs Superjeannot on map00: $wins/$limit${NC}"; else echo "${GREEN}$champion vs Superjeannot on map00: $wins/$limit${NC}"; fi

    # Testing SUPERJEANNOT on map01
    i=0
    wins=0
    while [[ $i -lt $limit ]]
    do
        ./resources/filler_vm -f resources/maps/map01 -p2 resources/players/superjeannot.filler -p1 ./$login.filler > trace
        enemy=`grep "== X" trace | cut -d: -f2`
        yours=`grep "== O" trace | cut -d: -f2`
        if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
        ((i++))
    done
    if [[ $wins -lt 3 ]]; then echo "${RED}$champion vs Superjeannot on map01: $wins/$limit${NC}"; else echo "${GREEN}$champion vs Superjeannot on map01: $wins/$limit${NC}"; fi

    # Testing SUPERJEANNOT on map02
    # i=0
    # wins=0
    # while [[ $i -lt $limit ]]
    # do
    #     ./resources/filler_vm -f resources/maps/map02 -p2 resources/players/superjeannot.filler -p1 ./$login.filler > trace
    #     enemy=`grep "== X" trace | cut -d: -f2`
    #     yours=`grep "== O" trace | cut -d: -f2`
    #     if [ $((yours)) -gt $((enemy)) ]; then ((wins++)); fi
    #     ((i++))
    # done
    # if [[ $wins -lt 3 ]]; then echo "${RED}$champion vs Superjeannot on map02: $wins/$limit${NC}"; else echo "${GREEN}$champion vs Superjeannot on map02: $wins/$limit${NC}"; fi


# Deleting trace file
rm trace
