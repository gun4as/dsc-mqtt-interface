
function resetForm() {
  document.getElementById('configForm').reset();
}

document.getElementById('configForm').addEventListener('submit', function(e) {
  e.preventDefault();
  const data = Object.fromEntries(new FormData(this).entries());
  fetch('/save', {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify(data)
  }).then(res => {
    if (res.ok) alert('Config saved!');
    else alert('Error saving config.');
  });
});
