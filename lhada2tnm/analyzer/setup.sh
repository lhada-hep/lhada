TNM_PATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
if [ "$PYTHONPATH" == "" ]; then
    export PYTHONPATH=$TNM_PATH/python
else
    export PYTHONPATH=$TNM_PATH/python:$PYTHONPATH
fi

if [ "$LD_LIBRARY_PATH" == "" ]; then
    export LD_LIBRARY_PATH=$TNM_PATH/lib
else
    export LD_LIBRARY_PATH=$TNM_PATH/lib:$LD_LIBRARY_PATH
fi
