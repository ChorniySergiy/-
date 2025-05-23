const URL = 'http://127.0.0.1:8000/';

// Завантаження списку записів
function loadRecords() {
  fetch(URL + 'clean/records/list')
    .then(response => response.json())
    .then(data => {
      const recordsList = document.getElementById('records-list');
      let html = '';

      data.forEach(record => {
        html += `
          <div>
            <h2>${record.name}</h2>
            <p>${record.comment}</p>
            <p>${record.address}</p>
            <button onclick="deleteRecord(${record.id})">Видалити</button>
          </div>
        `;
      });

      recordsList.innerHTML = html;
    })
    .catch(error => console.error('Помилка при отриманні списку записів:', error));
}

// Завантаження послуг
function loadServices() {
  fetch(URL + 'clean/services/list')
    .then(response => response.json())
    .then(data => {
      const serviceSelect = document.getElementById('service_id');
      data.forEach(service => {
        const option = document.createElement('option');
        option.value = service.id;
        option.text = service.title;
        serviceSelect.appendChild(option);
      });
    })
    .catch(error => console.error('Помилка при отриманні списку послуг:', error));
}

// Створення нового запису
function createRecord(e) {
  e.preventDefault();

  const form = document.getElementById('create-record-form');
  const formData = new FormData(form);

  fetch(URL + 'clean/records/create', {
    method: 'POST',
    body: formData
  })
    .then(response => {
      if (!response.ok) {
        throw new Error('Помилка при створенні запису');
      }
      return response.json();
    })
    .then(data => {
      console.log('Запис створено:', data);
      form.reset();       // Очистити форму
      loadRecords();      // Оновити список
    })
    .catch(error => console.error(error.message));
}

// Видалення запису
function deleteRecord(id) {
  fetch(URL + `clean/records/delete/${id}`, {
    method: 'DELETE'
  })
    .then(response => {
      if (!response.ok) {
        throw new Error('Помилка при видаленні запису');
      }
      return response.json();
    })
    .then(data => {
      console.log('Запис видалено:', data);
      loadRecords(); // Оновити список після видалення
    })
    .catch(error => console.error(error.message));
}

// Ініціалізація після завантаження сторінки
document.addEventListener('DOMContentLoaded', () => {
  loadRecords();
  loadServices();
  document.getElementById('create-record-form').addEventListener('submit', createRecord);
});
