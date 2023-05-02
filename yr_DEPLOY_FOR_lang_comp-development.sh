

YR_SD_RUNTIME_VERIF_LANG_HOME_DEVEL="${HOME}/yr_sd_runtime_verif_lang"

YR_SD_RUNTIME_VERIF_LANG_HOME_DEVEL_SRC="${YR_SD_RUNTIME_VERIF_LANG_HOME_DEVEL}/src"


YR_SD_RUNTIME_VERIF="yr_sd_runtime_verif"

SRC="src"


mkdir -p "${YR_SD_RUNTIME_VERIF_LANG_HOME_DEVEL_SRC}/${YR_SD_RUNTIME_VERIF}/yr-expressions-conditions"

mkdir -p "${YR_SD_RUNTIME_VERIF_LANG_HOME_DEVEL_SRC}/${YR_SD_RUNTIME_VERIF}/utils"

mkdir -p "${YR_SD_RUNTIME_VERIF_LANG_HOME_DEVEL}/lib"


cp "${SRC}"/*.hpp "${YR_SD_RUNTIME_VERIF_LANG_HOME_DEVEL_SRC}/${YR_SD_RUNTIME_VERIF}"

cp "${SRC}"/utils/YR_CPP_UTILS.hpp \
	"${YR_SD_RUNTIME_VERIF_LANG_HOME_DEVEL_SRC}/${YR_SD_RUNTIME_VERIF}/utils" 

cp -r "${SRC}"/yr-expressions-conditions/*.HPP \
	"${YR_SD_RUNTIME_VERIF_LANG_HOME_DEVEL_SRC}/${YR_SD_RUNTIME_VERIF}/yr-expressions-conditions"


cp lib/"lib${YR_SD_RUNTIME_VERIF}".a "${YR_SD_RUNTIME_VERIF_LANG_HOME_DEVEL}/lib"
