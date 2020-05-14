const socket = io('http://localhost:3000');

const mesForm = document.getElementById('send-form');
const mesInput = document.getElementById('mes-input');
const mesContainer = document.getElementsByClassName('mes')[0];

const name = prompt('What is your name?');
appendMes('You joined');
socket.emit('new-user', name);

socket.on('chat-mes', data => {
  appendMes(`${data.user}: ${data.mes}`);
});

socket.on('user-connected', name => {
  appendMes(`${name} connected`);
});

socket.on('user-disconnected', name => {
  appendMes(`${name} disconnected`);
});

mesForm.addEventListener('submit', e => {
  e.preventDefault();
  if (mesInput.value) {
    appendMes('You: ' + mesInput.value);
    socket.emit('send-mes', mesInput.value);
    mesInput.value = '';
  }
});

function appendMes(mes) {
  let mesDiv = document.createElement('div');
  mesDiv.innerHTML = `<span class="time">${new Date()}</span><span>${mes}</span>`;
  mesContainer.appendChild(mesDiv);
  mesContainer.lastChild.scrollIntoView();
}