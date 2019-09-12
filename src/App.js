import React, { Component } from 'react';
import logo from './logo.svg';
import './App.css';

class InputComponent extends React.Component {
  state = {
    inputValue: ""
  };

  changeHandler = (event) => {
    this.setState({inputValue: event.target.value})
  }

  render() {
    return (
    <div> 
	<input onChange={this.changeHandler} 
	type="text" 
	value={this.state.inputValue} 
	/>
    {this.state.inputValue}
    </div>
    )
  }
}


class App extends React.Component {
  state ={
    spriteUrl: ''
  };

  getPokemonData =async () => {
    const response = await fetch("https://pokeapi.co/api/v2/pokemon/9/");
    const pokeData = await response.json();

    //setState for spriteUrl to be an image of the pokemon. Sprites is the image.
    this.setState({spriteUrl: pokeData.sprites.front_default})

    console.log(pokeData); 
	//sends to the console, the info from the server that we just fetch() and promised from.
  }

  render() {
    return (
      <div>
	<button onClick={this.getPokemonData}>Click to get PokeInfo</button>
	<img src={this.state.spriteUrl} />
      </div>
    );
  }
}

export default App;

