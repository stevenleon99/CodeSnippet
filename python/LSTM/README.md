```
python -m venv lstm
D:\CodeSnippet\python\LSTM\lstm\Scripts> .\activate
pip install jupyter ipykernel
pip -r install requirements.txt
python -m ipykernel install --user --name=lstm --display-name "lstm"
```

launch the jupyter notebook
```
jupyter notebook
```

additional steps for gpu driver
```
nvidia-smi # see the version (CUDA 12.5 - install pytorch bundled cuda 12.1 libraries)
pip3 install torch torchvision torchaudio --index-url https://download.pytorch.org/whl/cu121
```

export the requirements
```
pip freeze > requirements.txt
```