import visualkeras
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Input

model = Sequential([
    Input(shape=(2,), name='InputLayer'),
    Dense(64, activation='relu', name='Dense1'),
    Dense(32, activation='relu', name='Dense2'),
    Dense(1, name='OutputLayer')
])

# Save to file and show
visualkeras.layered_view(model).show() # display using your system viewer
visualkeras.layered_view(model, to_file='output.png') # write to disk
visualkeras.layered_view(model, to_file='output.png').show() # write and show

visualkeras.layered_view(model)