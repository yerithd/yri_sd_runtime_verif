#!/bin/bash
#AUTEUR: DR.-ING. DIPL.-INF. XAVIER NOUNDOU
#EMAIL: yerith.d@gmail.com

YRI_ERRORS_LOG_FILE="yri_errors.log"

clear && qmake yri_sd_runtime_verif.pro && make clean 

OUT_CMD_TIME=$(time make -j8 > /dev/null 2> "${YRI_ERRORS_LOG_FILE}")

val=$(cat "${YRI_ERRORS_LOG_FILE}" | grep 'error\|ERROR\|Error' | wc -l)

if [ ${val} -eq 0 ]; then
	rm -f "${YRI_ERRORS_LOG_FILE}" 
	echo "[compilation avec succes]"
else
	echo "[compilation avec des erreurs (${val})]"
fi

echo ${OUT_CMD_TIME}


