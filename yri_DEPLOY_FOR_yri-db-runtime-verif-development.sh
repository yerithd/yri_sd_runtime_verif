

YRI_DB_RUNTIME_VERIF_HOME_DEVEL="${HOME}/yri-db-runtime-verif"

YRI_DB_RUNTIME_VERIF_HOME_DEVEL_SRC="${YRI_DB_RUNTIME_VERIF_HOME_DEVEL}/src"

YRI_SD_RUNTIME_VERIF="yri_sd_runtime_verif"

SRC="src"

cp "${SRC}"/*.hpp "${YRI_DB_RUNTIME_VERIF_HOME_DEVEL_SRC}/${YRI_SD_RUNTIME_VERIF}"

cp "${SRC}"/utils/YRI_CPP_UTILS.hpp \
	"${YRI_DB_RUNTIME_VERIF_HOME_DEVEL_SRC}/${YRI_SD_RUNTIME_VERIF}/utils" 

cp "${SRC}"/yri-expressions-conditions/*.HPP \
	"${YRI_DB_RUNTIME_VERIF_HOME_DEVEL_SRC}/${YRI_SD_RUNTIME_VERIF}/yri-expressions-conditions"

mkdir -p "${YRI_DB_RUNTIME_VERIF_HOME_DEVEL}/lib_SD"

cp lib/"lib${YRI_SD_RUNTIME_VERIF}".a "${YRI_DB_RUNTIME_VERIF_HOME_DEVEL}/lib_SD"