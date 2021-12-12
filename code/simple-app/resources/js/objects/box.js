function makeBox(geometry, color, x, y) {
    const material = new THREE.MeshPhongMaterial( {color} );

    const cube = new THREE.Mesh(geometry, material);
    
    scene.add(cube);

    cube.position.x = x;
    cube.position.y = y;

    return cube;
}

function makeLine(geometry, color, x, y) {
    const line = new THREE.Line( geometry, material );

    scene.add( line );
}